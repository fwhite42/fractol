/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strnstr.c                                            4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/11 20:23:59 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/11 20:26:24 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (len < ft_strlen(little) && big)
		return (NULL);
	if (*little == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (little[j] == big[i + j] && i + j < len)
		{
			j++;
			if (little[j] == 0)
				return (((char *)big) + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
