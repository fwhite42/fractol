/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_memset.c                                             4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/11 20:22:59 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/11 20:28:38 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *string, int value, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = string;
	while (i < len)
		ptr[i++] = (unsigned char) value;
	return (string);
}
