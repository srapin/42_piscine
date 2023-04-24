/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 05:55:12 by srapin            #+#    #+#             */
/*   Updated: 2022/10/05 07:18:36 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "tools.h"

t_sol	find_square(t_grid *grid, t_sol sol)
{
	t_point	point;
	point.col = sol.point.col;
	point.line = sol.point.line;
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (i < size && flag)
	{
		if (!ask_elem(cols[i + sol.col], sol.size) || !ask_elem(line[i + sol.line], sol.size))
			flag = 0;
		i++;
	}
	if (flag == 1)
	{
		sol.valid = 1;
		return sol;
	}
	sol.point.line++;
	if (find_square(grid, sol).valid)
		return sol;	
	sol.point.line--;
	sol.point.col++;
	if (find_square(grid, sol).valid)
		return sol;
	sol.point.col--;
	sol.point.size--;
	return(find_square(grid, sol));
}
