/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_memmove.c                                            4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/11 20:22:57 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/11 20:28:42 by fwhite42           _)/_\---/_\(_         */
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
