/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:35:37 by srapin            #+#    #+#             */
/*   Updated: 2022/10/01 14:39:38 by srapin           ###   ########.fr       */
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
	i = 0;
	if (sign == 1)
		to_ret[i++] = '-';
	ft_strncpy(to_ret + i, nbr_cvrt, base_size);
	return (to_ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nb;

	if (!(check_base(base_from) && check_base(base_to)))
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	return (itoa_base(nb, base_to, check_base(base_to), 0));
}
/*
#include <stdio.h>
int main(int ac, char ** av)
{
	if(ac > 3)
		printf("%s", ft_convert_base(av[1], av[2], av[3]));
}*/
