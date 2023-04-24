/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:48:34 by srapin            #+#    #+#             */
/*   Updated: 2022/10/06 02:24:48 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
/*
int	test(char * i)
{
	return (i[0] == 's');
}

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

int	*ft_range(int min, int max)
{
	int	size;
	int	*rgn;
	int	i;

	i = 0;
	size = max - min;
	if (size > 0)
	{
		rgn = malloc(size * sizeof(int));
		if (rgn == 0)
			return (0);
	}
	else
		return (0);
	while (min < max)
	{
		rgn[i] = min;
		i++;
		min++;
	}
	return (rgn);
}

int	main(int ac, char ** av)
{
	printf("%d", ft_any(av, &test));
	return (0);
}
*/
