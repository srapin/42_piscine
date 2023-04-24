/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:35:37 by srapin            #+#    #+#             */
/*   Updated: 2022/10/04 23:34:51 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_base(char *str);
int	ft_atoi_base(char *str, char *base);

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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

char	*ft_rev_int_tab(char *tab)
{
	char	tmp;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(tab);
	while (i < size - i - 1)
	{
		tmp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = tmp;
		i++;
	}
	return (tab);
}

char	*itoa_base(long long_nbr, char *base, int base_size, int sign)
{
	char		nbr_cvrt[32];
	int			i;
	char		*to_ret;

	i = 0;
	if (long_nbr < 0)
	{
		sign = 1;
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
	base_size = i;
	to_ret = malloc((base_size + sign) * sizeof(char));
	to_ret[i - 1] = '\0';
	ft_rev_int_tab(ft_strncpy(to_ret + sign, nbr_cvrt, base_size));
	if (sign == 1)
		to_ret[0] = '-';
	return (to_ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nb;

	if (check_base(base_from) < 2 || check_base(base_to) < 2)
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	return (itoa_base(nb, base_to, check_base(base_to), 0));
}
/*
#include <stdio.h>
int main(int ac, char ** av)
{
	printf("%d\n",atoi(av[0]));
	if(ac > 3)
		printf("%s", ft_convert_base(av[1], av[2], av[3]));
}
*/
