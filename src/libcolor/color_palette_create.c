/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   color_palette_create.c                                  4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/27 01:17:22 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 01:28:03 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libcolor.h"
#include"libft.h"
#include"liberror.h"
#include<stdio.h>

static int	_sum(int *tab, int tab_size)
{
	int	i;

	i = 0;
	while (tab_size--)
		i += (tab++)[tab_size];
	return (i);
}

int	*color_palette_create(int *clrs, int *duration, int nbr_of_clrs)
{
	int		*tab;
	int		size;
	double	j;
	int		i;
	int		k;

	size = _sum(duration, nbr_of_clrs);
	tab = ft_calloc(sizeof(int), size);
	if (tab == NULL)
		error_fatal("Out of memory", -42);
	i = 0;
	k = 0;
	while (i < nbr_of_clrs - 1)
	{
		j = 0;
		while (j < duration[i])
		{
			tab[k] = color_interpolate(clrs[i], clrs[i + 1], j / duration[i]);
			j++;
			k++;
		}
		i++;
	}
	return (tab);
}
