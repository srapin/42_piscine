/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:11:20 by byanis            #+#    #+#             */
/*   Updated: 2022/09/25 17:02:34 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
Print the grid and return 1 so no error message
*/

int	print_grid(int n, int grid[6][6])
{
	int	i;
	int	j;

	j = 1;
	while (j <= n)
	{
		i = 1;
		while (i <= n)
		{
			ft_putchar(grid[j][i] + '0');
			if (i != n)
				ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
	return (1);
}
