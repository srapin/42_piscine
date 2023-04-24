/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:26:00 by srapin            #+#    #+#             */
/*   Updated: 2022/09/29 18:42:46 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (-1);
	while (base[i])
	{
		j = i;
		while (base[j])
		{
			if (base[j] == '+' || base[j] == '-'
				|| (base[i] == base[j] && i != j))
				return (-1);
			j++;
		}
		i++;
	}
	return (ft_strlen(base));
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_size;
	char		nbr_cvrt[32];
	int			i;
	long int	long_nbr;

	long_nbr = nbr;
	i = 0;
	base_size = check_base(base);
	if (base_size < 2)
		return ;
	if (long_nbr < 0)
	{
		write(1, "-", 1);
		long_nbr *= -1;
	}
	while (long_nbr >= base_size)
	{
		nbr_cvrt[i] = base[long_nbr % base_size];
		long_nbr /= base_size;
		i++;
	}
	nbr_cvrt[i] = base[long_nbr % base_size];
	i++;
	while (--i >= 0)
		write(1, nbr_cvrt + i, 1);
}
/*
int	main(int ac, char * av[])
{
	if (ac == 3)
		ft_putnbr_base(atoi(av[1]), av[2]);	
}*/
