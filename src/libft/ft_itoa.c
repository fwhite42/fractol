/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 08:51:25 by fwhite42          #+#    #+#             */
/*   Updated: 2023/12/09 09:28:34 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<limits.h>

static int	_len(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		return (_len(-n) + 1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	_itoa(char **buff, int n)
{
	if (n > 9)
	{
		_itoa(buff, n / 10);
		(*buff)++;
	}
	**buff = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*buff;
	int		len;

	if (n == INT_MIN)
	{
		buff = (char *)malloc(12);
		if (!buff)
			return (NULL);
		ft_strlcpy(buff, "-2147483648", 12);
		return (buff);
	}
	len = _len(n);
	buff = (char *)malloc(len + 1);
	if (!buff)
		return (NULL);
	if (n < 0)
	{
		*buff = '-';
		buff++;
		n = -n;
	}
	_itoa(&buff, n);
	buff[1] = 0;
	return (buff - len + 1);
}
