#include"libcplx.h"

t_pt cplx_sum(t_pt z1, t_pt z2)
{
	z1.x += z2.x;
	z1.y += z2.y;
	return (z1);
}
