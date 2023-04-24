/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:24:50 by srapin            #+#    #+#             */
/*   Updated: 2022/10/02 11:13:58 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tools.h"

int	is_charset(char c, char *charset)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (charset[len])
		len++;
	while (i < len)
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		while (str[i] && is_charset(str[i], charset))
			i++;
		if (str[i] && !is_charset(str[i], charset))
		{
			cpt++;
			while (str[i] && !is_charset(str[i], charset))
				i++;
		}
	}
	return (cpt);
}

void	split_helper(char **split, char *str, char *charset, int words)
{
	int	j;
	int	k;
	int	i;

	i = 0;
	j = 0;
	k = 0;
	while (i < words)
	{
		while (str[j] && is_charset(str[j], charset))
			j++;
		k = 0;
		while (str[j + k] && !is_charset(str[j + k], charset))
			k++;
		split[i] = malloc((k + 1) * sizeof(char));
		ft_memset(split[i], 0, k + 1);
		if (split[i] != 0)
			ft_strncpy(split[i], &str[j], k);
		if (split[i] == 0)
		{
			while (i > 0)
			{
				i--;
				free(split[i]);
			}
			return;
		}
		j += k;
		i++;
	}
	i=0;
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		words;

	if (str == NULL)
		return (NULL);
	words = (count_words(str, charset));
	split = malloc(words * sizeof(char *));
	if (split == NULL)
		return (NULL);
	split_helper(split, str, charset, words);
	return (split);
}

/*
#include <stdio.h>
int main(int ac, char ** av)
{
	int i=0;
//	printf("jusquici tt va bien");
	char ** sp= ft_split(av[1], av[2]);
	while (sp != 0 && i < atoi(av[3]))
	{
		if (sp + i != 0)
			printf("%s \n", sp[i]);
		i++;
	}
}

*/