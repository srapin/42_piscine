/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:32:44 by syan              #+#    #+#             */
/*   Updated: 2022/09/17 17:40:14 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	get_char03(int curc, int curl, int col, int line)
{
	if (curl == 0)
	{
		if (curc == 0)
			return (0);
		else if (curc == col - 1)
			return (1);
		else
			return (4);
	}
	else if (curl == line - 1)
	{
		if (curc == 0)
			return (2);
		else if (curc == col - 1)
			return (3);
		else
			return (4);
	}
	else if (curc == 0 || curc == col - 1)
		return (5);
	return (6);
}

void	rush03(int col, int line)
{
	char	*caracters;
	int		curl;
	int		curc;
	int		car_pos;

	caracters = "ACACBB ";
	curl = 0;
	curc = 0;
	while (curl < line)
	{
		while (curc < col)
		{
			car_pos = get_char03(curc, curl, col, line);
			ft_putchar(caracters[car_pos]);
			curc++;
		}
		curc = 0;
		ft_putchar('\n');
		curl++;
	}
}
