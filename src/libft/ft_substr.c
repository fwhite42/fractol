/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_substr.c                                             4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/11 20:24:08 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/11 20:25:45 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *source, unsigned int start, size_t len)
{
	char	*str;
	size_t	total_length;

	if (source == NULL)
		return (NULL);
	total_length = ft_strlen(source);
	if (start >= total_length)
		return (ft_strdup(""));
	else if (start + len > total_length)
		len = total_length - start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, source + start, len + 1);
	return (str);
}
