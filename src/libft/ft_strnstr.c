/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 08:41:09 by fwhite42          #+#    #+#             */
/*   Updated: 2023/12/09 08:42:48 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (len < ft_strlen(little) && big)
		return (NULL);
	if (*little == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (little[j] == big[i + j] && i + j < len)
		{
			j++;
			if (little[j] == 0)
				return (((char *)big) + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
