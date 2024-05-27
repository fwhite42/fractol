/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_toupper.c                                            4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/11 20:24:17 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/11 20:25:37 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

static int	ft_islowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_toupper(int c)
{
	if (ft_islowercase(c))
		c -= 'a' - 'A';
	return (c);
}
