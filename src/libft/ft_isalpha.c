/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_isalpha.c                                            4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/11 20:22:30 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/11 20:27:23 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int character)
{
	if (character <= 'Z' && character >= 'A')
	{
		return (1);
	}
	else if (character <= 'z' && character >= 'a')
	{
		return (2);
	}
	return (0);
}
