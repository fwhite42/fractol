/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:38:10 by fwhite42          #+#    #+#             */
/*   Updated: 2023/12/09 09:38:14 by fwhite42         ###   ########.fr       */
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
