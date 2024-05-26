/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft2_double_to_str.c                                     4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 13:36:35 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/26 18:22:44 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */
#include<math.h>
#include"libft.h"
#include<stdlib.h>

char	*ft2_double_to_str(double x)
{
	char	*nbr;
	char	*tmp[2];
	int		integer_part;
	double	decimal_part;
	int		is_neg;

	is_neg = 0;
	if (x < 0)
	{
		is_neg = 1;
		x = -x;
	}
	integer_part = floor(x);
	decimal_part = floor(fabs((x - integer_part)) * 1000000000);
	tmp[1] = ft_itoa(integer_part);
	tmp[0] = ft_strjoin(tmp[1], ".");
	free(tmp[1]);
	tmp[1] = ft_itoa(floor(decimal_part));
	nbr = ft_strjoin(tmp[0], tmp[1]);
	free(tmp[1]);
	free(tmp[0]);
	if (is_neg)
	{
		tmp[0] = ft_strjoin("-", nbr);
		free(nbr);
		nbr = tmp[0];
	}
	return (nbr);
}
