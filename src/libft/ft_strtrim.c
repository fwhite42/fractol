/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 08:44:51 by fwhite42          #+#    #+#             */
/*   Updated: 2023/12/09 08:45:24 by fwhite42         ###   ########.fr       */
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
