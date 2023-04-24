/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:47:01 by srapin            #+#    #+#             */
/*   Updated: 2022/09/14 16:11:38 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_car(int i, int j, int k)
{
	char	c[5];

	c[3] = *",";
	c[4] = *" ";
	c[0] = i + '0';
	c[1] = j + '0';
	c[2] = k + '0';
	if (i == 7 && j == 8 && k == 9)
	{
		write(1, &c, 3);
	}
	else
	{
		write(1, &c, 5);
	}
}

void	ft_print_comb(void)
{	
	int	j;
	int	k;
	int	i;

	i = 0;
	while (i < 8)
	{
		j = i + 1;
		while (j < 9)
		{
			k = j + 1;
			while (k < 10)
			{
				if (i < j && j < k)
				{
					write_car(i, j, k);
				}
				k++;
			}
			j++;
		}
		i++;
	}
}
