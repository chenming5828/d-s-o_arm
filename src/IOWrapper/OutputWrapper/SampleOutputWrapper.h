/**
* This file is part of DSO.
* 
* Copyright 2016 Technical University of Munich and Intel.
* Developed by Jakob Engel <engelj at in dot tum dot de>,
* for more information see <http://vision.in.tum.de/dso>.
* If you use this code, please cite the respective publications as
* listed on the above website.
*
* DSO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* DSO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with DSO. If not, see <http://www.gnu.org/licenses/>.
*/


#pragma once
#include "boost/thread.hpp"
#include "util/MinimalImage.h"
#include "IOWrapper/Output3DWrapper.h"



#include "FullSystem/HessianBlocks.h"
#include "util/FrameShell.h"


#include <mavlink/v1.0/mavlink_types.h>
#include <mavlink/v1.0/common/mavlink.h>
#include <mavlink/v1.0/brisky/mavlink_msg_svo_position_raw.h>

#include "sender_receiver.h"


extern sem_t dso_send;

std::queue< mavlink_svo_position_raw_t> position;

namespace dso
{

class FrameHessian;
class CalibHessian;
class FrameShell;


namespace IOWrap
{
// std::ofstream log("/tmp/log_cor.txt", std::ios::out | std::ios:: trunc);
 struct timeval tv0, tv1;
 struct timeval tv2, tv3;
class SampleOutputWrapper : public Output3DWrapper
{
public:
        inline SampleOutputWrapper()
        {
            printf("OUT: Created SampleOutputWrapper\n");
            
        }

        virtual ~SampleOutputWrapper()
        {
            printf("OUT: Destroyed SampleOutputWrapper\n");
        }

        virtual void publishGraph(const std::map<uint64_t, Eigen::Vector2i, std::less<uint64_t>, Eigen::aligned_allocator<std::pair<const uint64_t, Eigen::Vector2i>>> &connectivity) override
        {
            printf("OUT: got graph with %d edges\n", (int)connectivity.size());

            int maxWrite = 5;

            for(const std::pair<uint64_t,Eigen::Vector2i> &p : connectivity)
            {
                int idHost = p.first>>32;
                int idTarget = p.first & ((uint64_t)0xFFFFFFFF);
                printf("OUT: Example Edge %d -> %d has %d active and %d marg residuals\n", idHost, idTarget, p.second[0], p.second[1]);
                maxWrite--;
                if(maxWrite==0) break;
            }
        }



        virtual void publishKeyframes( std::vector<FrameHessian*> &frames, bool final, CalibHessian* HCalib) override
        {
            struct timeval ttmp;
            gettimeofday(&tv3, NULL);
            timersub(&tv3, &tv2, &ttmp);

            std::cout <<"key frame time cost ================" << ttmp.tv_sec<< ":" << ttmp.tv_usec/1000 << "\n";
            tv2 =  tv3;

            for(FrameHessian* f : frames)
            {
                printf("OUT: KF %d (%s) (id %d, tme %f): %d active, %d marginalized, %d immature points. CameraToWorld:\n",
                       f->frameID,
                       final ? "final" : "non-final",
                       f->shell->incoming_id,
                       f->shell->timestamp,
                       (int)f->pointHessians.size(), (int)f->pointHessiansMarginalized.size(), (int)f->immaturePoints.size());
                std::cout << f->shell->camToWorld.matrix3x4() << "\n";


                int maxWrite = 5;
                for(PointHessian* p : f->pointHessians)
                {
                    printf("OUT: Example Point x=%.1f, y=%.1f, idepth=%f, idepth std.dev. %f, %d inlier-residuals\n",
                           p->u, p->v, p->idepth_scaled, sqrt(1.0f / p->idepth_hessian), p->numGoodResiduals );
                    maxWrite--;
                    if(maxWrite==0) break;
                }
            }
        }

        virtual void publishCamPose(FrameShell* frame, CalibHessian* HCalib) override
        {
            // printf("OUT: Current Frame %d (time %f, internal ID %d). CameraToWorld:\n",
            //        frame->incoming_id,
            //        frame->timestamp,
            //        frame->id);
            struct timeval ttmp;
            gettimeofday(&tv1, NULL);
            timersub(&tv1, &tv0, &ttmp);
 
            std::cout <<"time cost ================" << ttmp.tv_sec<< ":" << ttmp.tv_usec/1000 << "\n";
            tv0 =  tv1;

            mavlink_svo_position_raw_t sendmsg;

            Eigen::Matrix<double,3,4> matrix = frame->camToWorld.matrix3x4();
            Eigen::Quaterniond	q_out = frame->camToWorld.unit_quaternion();

            sendmsg.position_x = matrix(0,3);
            sendmsg.position_y = matrix(1,3);
            sendmsg.position_z = matrix(2,3);

            sendmsg.timestamp = frame->timestamp / 1000; /*< Timestamp of the component clock since boot time in milliseconds.*/
           
            sendmsg.q0 = q_out.w();
            sendmsg.q1 = q_out.x();
            sendmsg.q2 = q_out.y();
            sendmsg.q3 = q_out.z();
            sendmsg.svo_valid = 1;
            // send_svo_data(&sendmsg);
            
            // position.push(sendmsg);
            // sem_post(&dso_send);

            // uint8_t svo_valid; /*< Current svo state.*/
            // std::cout << "=================send out mavlink message ======================" << "\n";

            // std::cout << matrix << "\n";

            // log << sendmsg.position_x <<","<< sendmsg.position_y<<"," <<sendmsg.position_z <<"\n";
            // std::cout << sendmsg.position_y << "\n";
            // std::cout << sendmsg.position_z << "\n";


        }


        virtual void pushLiveFrame(FrameHessian* image) override
        {
            // can be used to get the raw image / intensity pyramid.
        }

        virtual void pushDepthImage(MinimalImageB3* image) override
        {
            // can be used to get the raw image with depth overlay.
        }
        virtual bool needPushDepthImage() override
        {
            return false;
        }

        virtual void pushDepthImageFloat(MinimalImageF* image, FrameHessian* KF ) override
        {
            printf("OUT: Predicted depth for KF %d (id %d, time %f, internal frame-ID %d). CameraToWorld:\n",
                   KF->frameID,
                   KF->shell->incoming_id,
                   KF->shell->timestamp,
                   KF->shell->id);
            std::cout << KF->shell->camToWorld.matrix3x4() << "\n";

            int maxWrite = 5;
            for(int y=0;y<image->h;y++)
            {
                for(int x=0;x<image->w;x++)
                {
                    if(image->at(x,y) <= 0) continue;

                    printf("OUT: Example Idepth at pixel (%d,%d): %f.\n", x,y,image->at(x,y));
                    maxWrite--;
                    if(maxWrite==0) break;
                }
                if(maxWrite==0) break;
            }
        }


};



}



}
