/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_putnbr_fd.c                                          4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/11 20:23:13 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/11 20:28:22 by fwhite42           _)/_\---/_\(_         */
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
