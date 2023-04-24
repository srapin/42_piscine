/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:11:04 by byanis            #+#    #+#             */
/*   Updated: 2022/09/25 16:33:24 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check_row(int row, int col, int n, int grid[6][6])
{
	int	i;

	i = 1;
	while (i <= n)
	{
		if (grid[row][i] == grid[row][col] && i != col)
			return (0);
		i++;
	}
	return (1);
}

int	check_col(int row, int col, int n, int grid[6][6])
{
	int	i;

	i = 1;
	while (i <= n)
	{
		if (grid[i][col] == grid[row][col] && i != row)
			return (0);
		i++;
	}
	return (1);
}

int	check_grid(int pos, int n, int grid[6][6])
{
	int	row;
	int	col;

	col = 0;
	row = 0;
	col = calc_col(col, pos, n);
	row = calc_row(row, pos, n);
	if (!check_row(row, col, n, grid))
		return (0);
	if (!check_col(row, col, n, grid))
		return (0);
	if (!check(row, col, n, grid))
		return (0);
	return (1);
}
