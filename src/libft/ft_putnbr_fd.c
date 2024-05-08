/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:32:56 by fwhite42          #+#    #+#             */
/*   Updated: 2023/12/09 09:33:21 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<limits.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == INT_MIN)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(-(n % 10), fd);
	}
	else if (n < 0)
	{
		digit = '-';
		write(fd, &digit, 1);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		digit = ((char)(n % 10)) + '0';
		write(fd, &digit, 1);
	}
}
