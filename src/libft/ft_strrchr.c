/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 08:40:55 by fwhite42          #+#    #+#             */
/*   Updated: 2023/12/09 08:40:59 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*str)
	{	
		if (*str == (char) c)
			ptr = (char *)str;
		str++;
	}
	if (*str == 0 && (char) c == 0)
		ptr = (char *)str;
	return (ptr);
}
