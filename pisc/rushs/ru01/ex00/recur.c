/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:11:23 by byanis            #+#    #+#             */
/*   Updated: 2022/09/25 17:01:19 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	calc_col(int col, int pos, int n)
{
	if (pos % n)
		col = pos % n;
	else
		col = n;
	return (col);
}

int	calc_row(int row, int pos, int n)
{
	if (pos % n)
		row = pos / n + 1;
	else
		row = pos / n;
	return (row);
}

/*
Execute Backtracking with current position + 1
col and row calculated just above
*/

int	backtrack(int pos, int n, int grid[6][6])
{
	int	row;
	int	col;
	int	val;

	col = 0;
	row = 0;
	col = calc_col(col, pos, n);
	row = calc_row(row, pos, n);
	val = 0;
	if (pos == n * n + 1)
		return (print_grid(n, grid));
	else
	{
		val = 0;
		while (++val <= n)
		{
			grid[row][col] = val;
			if (check_grid(pos, n, grid))
				if (backtrack(pos + 1, n, grid))
					return (1);
		}
		grid[row][col] = 0;
		return (0);
	}
}
