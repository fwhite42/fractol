/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_split.c                                              4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/11 20:23:24 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/11 20:26:12 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_read_word(const char **src, char sep)
{
	int		len;
	char	*word;

	len = 0;
	while (**src == sep && **src != 0)
		(*src)++;
	while ((*src)[len] != sep && (*src)[len] != 0)
		len++;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, *src, len + 1);
	*src += len;
	return (word);
}

void	ft_rsplit(int *i, char ***dst, const char **src, char sep)
{
	char	*word;
	int		j;

	j = *i;
	word = ft_read_word(src, sep);
	if (*dst == NULL && word == NULL )
		*i = -1;
	else if (*dst == NULL && *word == 0)
	{
		*dst = (char **)malloc((*i + 1) * sizeof(char *));
		if (*dst == NULL)
			*i = -1;
		free(word);
		word = NULL;
	}
	else if (*dst == NULL && *word != 0)
	{
		(*i)++;
		ft_rsplit(i, dst, src, sep);
	}
	if (*i < 0)
		free(word);
	else
		(*dst)[j] = word;
}

char	**ft_split(const char *src, char sep)
{
	char	**split;
	int		i;

	i = 0;
	split = NULL;
	ft_rsplit(&i, &split, &src, sep);
	return (split);
}
