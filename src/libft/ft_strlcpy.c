/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strlcpy.c                                            4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/11 20:23:45 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/11 20:26:07 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while ((i < dstsize - 1) && *(src + i))
		{
			dst[i] = src[i];
			i++;
		}
		*(dst + i) = 0;
	}
	while (*(src + i++))
		;
	return (i - 1);
}
