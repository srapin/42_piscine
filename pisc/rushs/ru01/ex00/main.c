/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:11:17 by byanis            #+#    #+#             */
/*   Updated: 2022/09/25 17:04:59 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush.h"

int	main(int argc, char **argv)
{
	int	grid[6][6];
	int	n;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	n = 4;
	init_grid(argv[1], n, grid);
	if (!backtrack(1, n, grid))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (0);
}
