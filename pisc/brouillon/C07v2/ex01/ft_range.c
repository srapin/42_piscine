/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:49:16 by srapin            #+#    #+#             */
/*   Updated: 2022/09/28 23:57:31 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*rgn;
	int	i;

	i = 0;
	size = max - min;
	if (size > 0)
	{
		rgn = malloc(size * sizeof(int));
		if (rgn == 0)
			return (0);
	}
	else
		return (0);
	while (min < max)
	{
		rgn[i] = min;
		i++;
		min++;
	}
	return (rgn);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int		*ft_range(int min, int max);


void	print_tab(int * tab, int size)
{
	unsigned int	i;
	char			c[2];

	
	i = 0;
	while(i < size)
	{
		printf("%d, ", tab[i]);
		i++;
	}
	write(1, "\n", 1);
}


int	main(int ac, char ** av)
{
//	print_tab( ft_range(0, 42));
//	print_tab( ft_range(-5, 42));
//	print_tab( ft_range(-13, -8));
//	print_tab( ft_range(-15, 0));
//	print_tab( ft_range(30, 42));
	int min;
	int max;
	min = atoi(av[1]);
	max = atoi(av[2]);
	if (ac > 1)
	{
		int * i = ft_range(min, max);
	if (min < max)
		print_tab(i, max - min + 1);
	}
	
}*/
