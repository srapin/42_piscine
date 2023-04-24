/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:47:45 by pjay              #+#    #+#             */
/*   Updated: 2022/09/18 15:59:56 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hide_rush(int col, int line, int ex);

int		ft_atoi(char *str);

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		write(2, "Error !\n", 8);
		write(1, "Expected : ./a.out col line rushnb", 34);
		return (-1);
	}
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[2]) < 1
		|| ft_atoi(argv[3]) < 0 || ft_atoi(argv[3]) > 4)
	{
		write(1, "Arguments must be positiv and ex<5", 35);
		return (-1);
	}
	hide_rush(ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]));
	return (0);
}
