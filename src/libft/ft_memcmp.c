/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:35:06 by fwhite42          #+#    #+#             */
/*   Updated: 2023/12/09 09:35:10 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (s1 == s2 || n == 0)
		return (0);
	else if (*(unsigned char *)s1 - *(unsigned char *)s2 != 0 || n == 0)
		return ((*(unsigned char *)s1 - *(unsigned char *)s2));
	else
		return (ft_memcmp(s1 + 1, s2 + 1, n - 1));
}
