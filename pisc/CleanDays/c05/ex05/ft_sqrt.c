/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 08:06:12 by srapin            #+#    #+#             */
/*   Updated: 2022/09/28 16:28:32 by srapin           ###   ########.fr       */
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
		return (0);
	else if ((mid * mid) < nb)
		return (search_sqrt(mid + 1, high, nb));
	else
		return (search_sqrt(low, mid, nb));
}

int	ft_sqrt(int nb)
{
	return (search_sqrt(0, nb, nb));
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
	if (ac == 2)
		printf("%d", ft_sqrt(atoi(av[1])));
	else
		printf("too few args");
}
*/
