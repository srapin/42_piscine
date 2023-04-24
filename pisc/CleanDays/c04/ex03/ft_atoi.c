/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 07:48:14 by srapin            #+#    #+#             */
/*   Updated: 2022/09/25 05:38:01 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	convert(char c)
{
	const int	converter[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	if (c >= '0' && c <= '9')
		return (converter[c - '0']);
	else
		return (-1);
}

int	ft_atoi(char *str)
{
	long int	nb;
	int			i;
	int			sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (convert(str[i]) < 0)
			break ;
		nb = nb * 10 + convert(str[i]);
		i++;
	}
	return ((int)(sign * nb));
}

/*
#include <stdio.h>
int main(int ac, char * av[])
{
	if (ac == 2)	
		printf("%d", ft_atoi(av[1]));
}*/
