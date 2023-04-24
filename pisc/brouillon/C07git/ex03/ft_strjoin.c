/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 01:38:19 by srapin            #+#    #+#             */
/*   Updated: 2022/10/01 20:51:31 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	total_lenght(int size, char **strs, char *sep)
{
	int	cmp;
	int	i;

	i = 0;
	cmp = 0;
	while (i < size)
	{
		cmp += ft_strlen(strs[i]);
		i++;
	}
	cmp += (size - 1) * ft_strlen(sep);
	return (cmp);
}

int	ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;
	int		i;
	int		j;
	int		total_size;
	int		sizeofcharset;

	i = 0;
	j = 0;
	total_size = total_lenght(size, strs, sep);
	join = malloc(total_size * sizeof(char));
	if (join == 0)
		return (0);
	sizeofcharset = ft_strlen(sep);
	while (i < total_size)
	{
		i += ft_strncpy((join + i), strs[j], ft_strlen(strs[j]));
		if (j < size - 1)
			i += ft_strncpy((join + i), sep, sizeofcharset);
		j++;
	}
	join[++i] = '\0';
	return (join);
}
/*
int main (int ac, char *av)
{
	printf("%s", ft_strjoin(ac, av, "____"));
}*/
