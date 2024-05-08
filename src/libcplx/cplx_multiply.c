#include"libcplx.h"

t_pt cplx_multiply(t_pt z1, t_pt z2)
{
	t_pt z;
	
	z.x = z1.x * z2.x - z1.y * z2.y;
	z.y = z1.x * z2.y + z1.y * z2.x;
	return (z);
}
