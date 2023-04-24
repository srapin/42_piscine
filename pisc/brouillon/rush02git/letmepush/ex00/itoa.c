/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 01:50:23 by srapin            #+#    #+#             */
/*   Updated: 2022/10/02 19:38:58 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"


void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_rev_char_tab(char *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - i - 1)
	{
		ft_swap(&tab[i], &tab[size - i - 1]);
		i++;
	}
}

char	*ft_itoa(long long int long_nbr)
{
	char		nbr_cvrt[1000];
	int			i;
	char		*to_ret;
	const char	*base = "0123456789";
	int	size;
	int sign;

	if (long_nbr<0)
		return NULL;
	ft_memset(nbr_cvrt, 0, 1000);
	i = 0;
	sign = 0;
	if (long_nbr < 0)
	{
		sign = 1;
		long_nbr *= -1;
	}
	while (long_nbr >= 10)
	{
		nbr_cvrt[i] = base[long_nbr % 10];
		long_nbr /= 10;
		i++;
	}
	nbr_cvrt[i] = base[long_nbr % 10];
	i++;
	size = i;
	to_ret = malloc((size + 2) * sizeof(char));
	if (to_ret == NULL)
		return (0);
	ft_memset(to_ret, 0, size+sign);
	i = 0;
	if (sign == 1)
	{
		to_ret[0] = '-';
		to_ret++;
	}
	ft_strncpy(to_ret, nbr_cvrt, 10);
	ft_rev_char_tab(to_ret, size+sign);
	return (to_ret);
}
