#ifndef QUAT_EULER_H
#define QUAT_EULER_H
#include <stdio.h>
#include <math.h>

typedef struct Quaternion3d
{
    float w, x, y, z;
    Quaternion3d (float w_, float x_, float y_, float z_) 
                : w(w_), x(x_), y(y_), z(z_) {}
}Quaternion3d;

typedef struct Euler_rads
{
    float x, y, z;
	Euler_rads (float x_, float y_, float z_)
			 	: x(x_), y(y_), z(z_) {}
} Euler_rads;

//void quat_to_matrix(Quaternion3d& q, float* matrix);
void rads_to_quat(Euler_rads& rads, Quaternion3d& q);
void quat_to_rads(Quaternion3d& q, Euler_rads& rads);
void quat_to_matrix(Quaternion3d& q, float* matrix);
void quat_normalize(Quaternion3d& q);
void quat_mult(Quaternion3d& q1, Quaternion3d& q2, Quaternion3d& q_out);
void rads_to_quat(Euler_rads& rads, Quaternion3d& q);


#endif
