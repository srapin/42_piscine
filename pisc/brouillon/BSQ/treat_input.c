/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 05:36:52 by srapin            #+#    #+#             */
/*   Updated: 2022/10/05 05:54:46 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tools.h>

char	*treat_input(int to_read, char **av)
{
	char	*input;
	t_grid	*grid;

	if (to_read == 0)
		input = read_std_in();
	else
		input = read_file(av[to_read]);
	if (!input)
		return	(MAP_ERROR);
	make_grid(grid, input);
	if (!grid->valid)
		return (MAP_ERROR);
	file_grid(grid);
	return (ft_join(grid->size, grid->map, ''));
}
