/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 08:49:19 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/01 21:31:42 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static inline void	ft_memcpy_rl(void *dst, const void *src, size_t len)
{
	while (len--)
		((char *)dst)[len] = ((char *)src)[len];
}

static inline void	ft_memcpy_lr(void *dst, const void *src, size_t len)
{
	while (len--)
		*((char *)(dst++)) = *((char *)(src++));
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst != src)
	{
		if (src < dst && src + len > dst)
			ft_memcpy_rl(dst, src, len);
		else
			ft_memcpy_lr(dst, src, len);
	}
	return (dst);
}
