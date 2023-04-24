/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 04:44:09 by srapin            #+#    #+#             */
/*   Updated: 2022/10/05 07:18:41 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

typedef struct s_point
{
	int	line;
	int	col;
}	t_point;

typedef struct s_sol
{
	int	size;
	int	valid
	t_point	indice;
}	t_sol;

typedef struct s_line_o_col
{
	int	size;
	int	*pos_sep;
}	t_line_o_col;

typedef struct s_grid
{
	char		**map;
	char		*use_chars;
	int		valid;
	int		size;
	t_line_o_col	*cols;
	t_line_o_col	*lines;
}	t_grid;

char	*ft_strjoin(int size, char **strs, char *sep);
char	*treat_input(int to_read, char **av);
char	*read__std_in();
char	*read_file(char* file);
t_grid	*make_grid(t_grid *grid, fill_with);
void	fill_grid(t_grid *grid);
void	make_elem(t_line_o_col *l_o_c, int size, int *pose_sep);
int	get_max_size(t_grid grid);
int	ask_elem(t_line_o_col elem, int indice, int size);
t_sol	find_square(t_grid *grid, t_sol sol);

#define TRUE = 1
#define FALSE = 0
#define MAP_ERROP = map error
#endif
 
