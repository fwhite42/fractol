/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strlcat.c                                            4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/11 20:23:43 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/11 20:26:30 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	tot;

	len = ft_strlen(dst);
	tot = ft_strlen(dst) + ft_strlen(src);
	if (dstsize < len)
		return (dstsize + (tot - len));
	dst += len;
	while (dstsize-- > len + 1 && *src)
	{
		*(dst++) = *(src++);
	}
	*dst = 0;
	return (tot);
}
