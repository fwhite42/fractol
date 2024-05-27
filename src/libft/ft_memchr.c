/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_memchr.c                                             4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/11 20:22:50 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/11 20:28:05 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (*(str + i) == (unsigned char) c)
			return (str + i);
		i++;
	}
	return (NULL);
}
