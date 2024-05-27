/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_tolower.c                                            4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/11 20:24:12 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/11 20:25:41 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

static inline int	ft_isuppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_tolower(int c)
{
	if (ft_isuppercase(c))
		c += 'a' - 'A';
	return (c);
}
