#ifndef LIBCPLX_H
# define LIBCPLX_H
typedef struct s_pt	t_pt;

struct s_pt
{
	double	x;
	double	y;
};

t_pt	cplx_zero(void);
double	cplx_abs(t_pt z);
t_pt	cplx_square(t_pt z);
t_pt	cplx_sum(t_pt z1, t_pt z2);
t_pt	cplx_multiply(t_pt z1, t_pt z2);
#endif
