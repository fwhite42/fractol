/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:41:59 by fwhite42          #+#    #+#             */
/*   Updated: 2023/12/08 22:42:29 by fwhite42         ###   ########.fr       */
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