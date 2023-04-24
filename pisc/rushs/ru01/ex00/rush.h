/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:11:26 by byanis            #+#    #+#             */
/*   Updated: 2022/09/25 17:00:54 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		check_grid(int pos, int n, int grid[6][6]);
int		print_grid(int n, int grid[6][6]);
int		check_left_right(int row, int n, int grid[6][6]);
int		check(int row, int col, int n, int grid[6][6]);
void	init_grid(char *str, int n, int grid[6][6]);
int		backtrack(int pos, int n, int grid[6][6]);
int		calc_row(int row, int pos, int n);
int		calc_col(int col, int pos, int n);

#endif
