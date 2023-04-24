/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:29:30 by srapin            #+#    #+#             */
/*   Updated: 2022/10/01 20:47:45 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;
	int	*rgn;

	i = 0;
	size = (max - min);
	if (size <= 0)
	{
		range = 0;
		return (0);
	}
	rgn = malloc(size * sizeof(int));
	if (rgn == 0)
		return (-1);
	while (min < max)
	{
		rgn[i] = min;
		min++;
		i++;
	}
	*range = rgn;
	return (size);
}
