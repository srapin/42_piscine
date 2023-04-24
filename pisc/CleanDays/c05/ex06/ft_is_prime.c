/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 08:24:26 by srapin            #+#    #+#             */
/*   Updated: 2022/09/28 23:32:52 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	search_sqrt(int low, int high, int nb)
{
	long int	mid;

	mid = (low + high) / 2;
	if ((mid * mid) == nb)
		return (mid);
	if (low > high)
		return (0);
	if ((mid * mid) <= nb && (((mid + 1) * (mid + 1)) > nb))
		return (mid + 1);
	else if ((mid * mid) < nb)
		return (search_sqrt(mid + 1, high, nb));
	else
		return (search_sqrt(low, mid, nb));
}

int	rec_prime(long int div, long int nb, long int sq)
{
	if (nb <= 2)
		return (nb == 2);
	if (nb == 3)
		return (1);
	if (nb % div == 0)
		return (0);
	if (div > sq)
		return (1);
	else
		return (rec_prime(div + 1, nb, sq));
}

int	ft_sqrt(int nb)
{
	return (search_sqrt(0, nb, nb));
}

int	ft_is_prime(int nb)
{
	int	sq;

	sq = ft_sqrt(nb);
	return (rec_prime(2, nb, sq));
}

/*
#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
	if (ac == 2)
		
//		printf("%d", ft_sqrt(atoi(av[1])));
		printf("%d", ft_is_prime(atoi(av[1])));
	else
		printf("too few args");
}*/
