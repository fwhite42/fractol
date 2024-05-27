/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft2_double_to_str.c                                     4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 13:36:35 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 10:41:06 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */
#include<math.h>
#include"libft.h"
#include<stdlib.h>

static void	__handle_neg1(double *x, int *is_neg)
{
	*is_neg = 0;
	if (x < 0)
	{
		*is_neg = 1;
		*x = -(*x);
	}
}

static void	__handle_neg2(char **str, char **dst, int is_neg)
{
	if (is_neg)
	{
		*dst = ft_strjoin("-", *str);
		free(*str);
		*str = *dst;
	}
}

char	*ft2_double_to_str(double x)
{
	char	*nbr;
	char	*tmp[2];
	int		integer_part;
	double	decimal_part;
	int		is_neg;

	__handle_neg1(&x, &is_neg);
	integer_part = floor(x);
	decimal_part = floor(fabs((x - integer_part)) * 1000000000);
	tmp[1] = ft_itoa(integer_part);
	tmp[0] = ft_strjoin(tmp[1], ".");
	free(tmp[1]);
	tmp[1] = ft_itoa(floor(decimal_part));
	nbr = ft_strjoin(tmp[0], tmp[1]);
	free(tmp[1]);
	free(tmp[0]);
	__handle_neg2(&nbr, tmp, is_neg);
	return (nbr);
}
