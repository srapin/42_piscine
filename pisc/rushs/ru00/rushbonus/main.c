/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:11:42 by syan              #+#    #+#             */
/*   Updated: 2022/09/17 17:35:10 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush00(int col, int line);

void	rush01(int col, int line);

void	rush02(int col, int line);

void	rush03(int col, int line);

int	main(void)
{
	rush00(5, 3);
	write(1, "\n", 1);
	rush01(5, 1);
	write(1, "\n", 1);
	rush02(1, 1);
	write(1, "\n", 1);
	rush03(1, 5);
	write(1, "\n", 1);
	return (0);
}
