#include"libcplx.h"
#include"math.h"

double cplx_abs(t_pt z)
{
	return sqrt(z.x * z.x + z.y * z.y);
}
