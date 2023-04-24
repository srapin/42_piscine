/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 01:36:06 by srapin            #+#    #+#             */
/*   Updated: 2022/10/02 19:37:55 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tools.h"


int	convert_at(char c)
{
	const int	converter[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	if (c >= '0' && c <= '9')
		return (converter[c - '0']);
	else
		return (-1);
}

long long int	ft_atoi_dict(char *str)
{
	long long int	nb;
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
		if (convert_at(str[i]) < 0)
			break ;
		nb = nb * 10 + convert_at(str[i]);
		i++;
	}
	return (nb);
}
