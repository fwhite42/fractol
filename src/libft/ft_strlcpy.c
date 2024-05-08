/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 08:44:26 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/01 18:56:42 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while ((i < dstsize - 1) && *(src + i))
		{
			dst[i] = src[i];
			i++;
		}
		*(dst + i) = 0;
	}
	while (*(src + i++))
		;
	return (i - 1);
}
