/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strtrim.c                                            4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/11 20:24:05 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/11 20:26:01 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrim(char const *src, const char *set)
{
	size_t	len;
	char	*dst;

	while (!!ft_strchr(set, *src) && *src)
		src++;
	len = ft_strlen(src);
	if (!len)
	{
		dst = (char *) malloc(1);
		if (!dst)
			return (NULL);
		*dst = 0;
		return (dst);
	}
	while (!!ft_strchr(set, src[len - 1]))
		len--;
	dst = (char *)malloc(len + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, src, len + 1);
	return (dst);
}
