/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:53:13 by srapin            #+#    #+#             */
/*   Updated: 2022/09/20 03:55:41 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= -1;
		}
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
			ft_putchar('0' + nb % 10);
		}
		else
			ft_putchar('0' + nb % 10);
	}
}

void	fill_and_print_tab(int *nb_tab, int nb, int nb_max, int n)
{
	int	i;
	int	nb_cpy;

	i = n;
	nb_cpy = nb;
	while (--i != -1)
	{
		if (nb_cpy % 10 > (nb_cpy / 10) % 10)
		{
			nb_tab[i] = nb_cpy % 10;
			nb_cpy /= 10;
		}
		else
			break ;
	}
	if (i < 1)
	{
		i = -1;
		while (i++ < n - 1)
		{
			ft_putnbr(nb_tab[i]);
		}
		if (nb != nb_max)
			write(1, ", ", 2);
	}
}

void	ft_print_combn(int n)
{
	int	nb_max;
	int	nb_tab[10];
	int	nb;
	int	nb_cpy;
	int	i;

	i = n;
	nb = 0;
	nb_cpy = 0;
	nb_max = 0;
	while (i--)
	{
		nb_max *= 10;
		nb_max += (9 - i);
	}
	while (nb_cpy < 10)
	{
		nb_tab[nb_cpy] = 0;
		nb_cpy += 1;
	}
	nb--;
	while (++nb <= nb_max)
		fill_and_print_tab(nb_tab, nb, nb_max, n);
}
