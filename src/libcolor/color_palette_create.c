#include"libcolor.h"
#include"libft.h"
#include"liberror.h"
#include<stdio.h>

static int _sum(int *tab, int tab_size)
{
	int	i;

	i = 0;
	while (tab_size--)
		i += (tab++)[tab_size];
	return (i);
}

int	*color_palette_create(int *colors, int *duration, int nbr_of_colors)
{
	int	*tab;
	int	size;
	double	j;
	int	i;
	int	k;

	size = _sum(duration, nbr_of_colors);
	tab = ft_calloc(sizeof(int), size);
	if (tab == NULL)
		error_fatal("Out of memory", -42);
	i = 0;
	k = 0;
	while (i < nbr_of_colors - 1)
	{
		j = 0;
		while (j < duration[i])
		{
		//	printf("Creating color %i\n", k);
			tab[k] = color_interpolate(colors[i], colors[i + 1], j / duration[i]);
			j++;
			k++;
		}
		i++;
	}
	return (tab);
}
