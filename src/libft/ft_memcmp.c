/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_memcmp.c                                             4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/11 20:22:52 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/11 20:28:10 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (s1 == s2 || n == 0)
		return (0);
	else if (*(unsigned char *)s1 - *(unsigned char *)s2 != 0 || n == 0)
		return ((*(unsigned char *)s1 - *(unsigned char *)s2));
	else
		return (ft_memcmp(s1 + 1, s2 + 1, n - 1));
}
