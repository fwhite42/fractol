/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 08:40:12 by fwhite42          #+#    #+#             */
/*   Updated: 2023/12/10 15:49:01 by fwhite42         ###   ########.fr       */
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
