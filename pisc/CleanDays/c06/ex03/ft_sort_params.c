/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:02:05 by srapin            #+#    #+#             */
/*   Updated: 2022/09/25 21:11:16 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(char *a[], char *b[])
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
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
	if (s1[i] && !s2[i])
	{
		return (1);
	}
	if (!s1[i] && s2[i])
	{
		return (-1);
	}
	return (0);
}

void	ft_sort_int_tab(char *tab[], int size)
{
	int	i;

	i = 1;
	while (i < size - 1)
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 1;
		}
		else
		{
			i++;
		}
	}
}

int	main(int nb, char *c[])
{
	int	i;
	int	j;

	ft_sort_int_tab(c, nb);
	i = 1;
	j = 0;
	while (i < nb)
	{
		j = 0;
		while (c[i][j])
		{
			write(1, c[i] + j, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
