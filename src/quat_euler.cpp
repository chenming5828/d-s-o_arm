#include <quat_euler.h>

void quat_normalize(Quaternion3d& q)
{
    float norm = sqrt(q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);
    if (fabs(norm - 1) < 0.00001) 
		return;

    q.w /= norm;
    q.x /= norm;
    q.y /= norm;
    q.z /= norm;
}

void quat_to_rads(Quaternion3d& q, Euler_rads& rads)
{
	float ysqr = q.y * q.y;
	float t0 = -2.0f * (ysqr + q.z * q.z) + 1.0f;
	float t1 = +2.0f * (q.x * q.y - q.w * q.z);
	float t2 = -2.0f * (q.x * q.z + q.w * q.y);
	float t3 = +2.0f * (q.y * q.z - q.w * q.x);
	float t4 = -2.0f * (q.x * q.x + ysqr) + 1.0f;

	t2 = t2 > 1.0f ? 1.0f : t2;
	t2 = t2 < -1.0f ? -1.0f : t2;

	rads.x = asin(t2);
	rads.y = atan2(t3, t4);
	rads.z = atan2(t1, t0);
}

void rads_to_quat(Euler_rads& rads, Quaternion3d& q)
{
    double c1, c2, c3, s1, s2, s3;
    c1 = cos(rads.x / 2);
    c2 = cos(rads.y / 2);
    c3 = cos(rads.z / 2);
    s1 = sin(rads.x / 2);
    s2 = sin(rads.y / 2);
    s3 = sin(rads.z / 2);
    q.w = c1 * c2 * c3 + s1 * s2 * s3;
    q.x = s1 * c2 * c3 - c1 * s2 * s3;
    q.y = c1 * s2 * c3 + s1 * c2 * s3;
    q.z = c1 * c2 * s3 - s1 * s2 * c3;

    quat_normalize(q);
}

void quat_to_matrix(Quaternion3d& q, float* matrix)
{
    quat_normalize(q);
    float qw = q.w;
    float qx = q.x;
    float qy = q.y;
    float qz = q.z;

    matrix[0] = 1 - 2*qz*qz- 2*qy*qy;
    matrix[1] = -2* qz*qw+2*qy*qx;
    matrix[2] = 2*qy*qw +2* qz*qx;
    matrix[3] = 2*qx*qy+ 2*qw*qz;
    matrix[4] = 1 - 2*qz*qz - 2*qx*qx;
    matrix[5] = 2*qz*qy- 2*qx*qw;
    matrix[6] = 2*qx*qz- 2*qw*qy;
    matrix[7] = 2*qy*qz + 2*qw*qx;
    matrix[8] = 1- 2*qy*qy- 2*qx*qx;
}

void quat_mult(Quaternion3d& q1, Quaternion3d& q2, Quaternion3d& q_out)
{
    Quaternion3d qa = {q1.x, q1.y, q1.z, q1.w};
    Quaternion3d qb = {q2.x, q2.y, q2.z, q2.w};
    q_out.w = qa.w * qb.w - qa.x * qb.x - qa.y * qb.y - qa.z * qb.z;
    q_out.x = qa.w * qb.x + qa.x * qb.w + qa.y * qb.z - qa.z * qb.y;
    q_out.y = qa.w * qb.y - qa.x * qb.z + qa.y * qb.w + qa.z * qb.x;
    q_out.z = qa.w * qb.z + qa.x * qb.y - qa.y * qb.x + qa.z * qb.w;
}

