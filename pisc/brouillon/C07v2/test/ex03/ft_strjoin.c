/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 01:38:19 by srapin            #+#    #+#             */
/*   Updated: 2022/10/03 03:22:13 by srapin           ###   ########.fr       */
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
		if (strs[i])
			cmp += ft_strlen(strs[i]);
		i++;
	}
	cmp += (size - 1) * ft_strlen(sep);
	return (cmp + 1);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!dest)
		return (0);
	i = ft_strlen(dest);
	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;
	int		j;
	int		total_size;

	j = 0;
	total_size = total_lenght(size, strs, sep);
	join = malloc((total_size + 1) * sizeof(char));
	if (join == 0)
		return (0);
	join[0] = '\0';
	while (j < size)
	{
		ft_strcat(join, strs[j]);
		if (j < size - 1)
			ft_strcat(join, sep);
		j++;
	}
	return (join);
}
/*
int main (int ac, char **av)
{
	char *c;
	c = ft_strjoin(ac, av, "*___");
	printf("%s", c);
	free(c);
}
*/
