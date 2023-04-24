/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 01:28:40 by srapin            #+#    #+#             */
/*   Updated: 2022/10/02 11:45:36 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"


char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n )
	{
		if (s1[i] > s2[i])
		{
			return (1);
		}
		if (s1[i] < s2[i])
		{
			return (-1);
		}
		i++;
	}
	if (i == n)
		return (0);
	if (s1[i] && !s2[i])
		return (1);
	if (!s1[i] && s2[i])
		return (-1);
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	len_to_find;

	i = -1;
	len_to_find = ft_strlen(to_find);
	if (!*to_find)
		return (str);
	while (str[++i])
		if (ft_strncmp(str + i, to_find, len_to_find) == 0)
			return (str + i);
	return (0);
}

void	ft_memset(char *ptr, int val, int size)
{
	int	i;

	i = 0;
	while(i < size)
	{
		*(ptr + i) = val;
		i++;
	}
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

long long int	ft_pow(int a, int b)
{
	if (b < 0)
		return (0);
	if (b == 0)
		return (1);
	else
		return (a * ft_pow(a, b - 1));
}