#include"libcplx.h"

double fractol_evaluate(t_pt c, int max_iteration, t_pt (*next)(t_pt z, t_pt c))
{
	t_pt z;
	int i;
	
	i = 0;
	z = cplx_zero();
	while (i < max_iteration)
	{
		z = next(z, c);
		if (cplx_abs(z) >= 2)
			break;
		i++;
	}
	return (i);
}
