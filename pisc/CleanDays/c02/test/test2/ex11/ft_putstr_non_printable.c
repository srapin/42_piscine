/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 05:58:14 by srapin            #+#    #+#             */
/*   Updated: 2022/09/24 11:49:16 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_non_print(char d)
{
	char		*c;
	long int	i;

	i = (unsigned char) d;
	c = "0123456789abcdef";
	ft_putchar(c[i / 16]);
	ft_putchar(c[i % 16]);
}

int	ft_str_is_printable(char str)
{
	if (str >= ' ' && str < 127)
		return (1);
	else
		return (0);
}

int	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_str_is_printable(str[i]))
		{
			ft_putchar('\\');
			ft_put_non_print(str[i]);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
	return (0);
}
