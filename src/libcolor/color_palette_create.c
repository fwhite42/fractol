#include"libcolor.h"

int	*color_palette_create(int size, int (*color_picker)(double x))
{
	int	*tab;

	tab = ft_calloc(sizeof(int), size);
	if (tab == NULL)
		error_fatal("Out of memory", -42);
	while (size--)
		tab[size] = color_picker(size);
}
