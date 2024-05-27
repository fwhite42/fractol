/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strrchr.c                                            4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/11 20:24:02 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/11 20:26:20 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*str)
	{	
		if (*str == (char) c)
			ptr = (char *)str;
		str++;
	}
	if (*str == 0 && (char) c == 0)
		ptr = (char *)str;
	return (ptr);
}
