/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_isdigit.c                                            4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/11 20:22:38 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/11 20:27:29 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int character)
{
	if (character >= '0' && character <= '9')
		return (1);
	else
		return (0);
}
