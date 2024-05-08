/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 08:45:41 by fwhite42          #+#    #+#             */
/*   Updated: 2023/12/09 08:45:45 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	tot;

	len = ft_strlen(dst);
	tot = ft_strlen(dst) + ft_strlen(src);
	if (dstsize < len)
		return (dstsize + (tot - len));
	dst += len;
	while (dstsize-- > len + 1 && *src)
	{
		*(dst++) = *(src++);
	}
	*dst = 0;
	return (tot);
}
