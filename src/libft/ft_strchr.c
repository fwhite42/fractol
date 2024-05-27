/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strchr.c                                             4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/11 20:23:29 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/11 20:23:29 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (c == 0)
		while (*s)
			s++;
	else
	{
		while (*s != (char) c)
		{
			if (*s == 0)
				return (NULL);
			s++;
		}
	}
	return ((char *)s);
}
