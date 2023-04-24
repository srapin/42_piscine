/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 00:30:41 by srapin            #+#    #+#             */
/*   Updated: 2022/10/06 18:33:00 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hexa(long pakeladresse, int iter)
{
	char const*const	hexa = "0123456789abcdef";

	if (pakeladresse < 0)
		pakeladresse = pakeladresse + 256;
	if (iter == -1 && pakeladresse < 16)
		write(1, "0", 1);
	if (pakeladresse >= 16)
		print_hexa(pakeladresse / 16, --iter);
	else
	{
		while (--iter > 0)
			ft_putchar('0');
	}
	ft_putchar(hexa[pakeladresse % 16]);
}

void	ft_print_line(char *line, int total_size, int i)
{
	char	f_nor[18];

	ft_strcpy(f_nor, "0123456789abcdef\n\0");
	while (i < 16)
	{
		if (i < total_size)
		{
			print_hexa((long) line[i], -1);
			if (line[i] >= 32 && line[i] < 127)
				f_nor[i] = line[i];
			else
				f_nor[i] = '.';
		}
		else
		{
			write(1, "  ", 2);
			f_nor[i] = '\0';
		}
		i ++;
		if (!(i % 2))
			ft_putchar(' ');
	}
	i = -1;
	while (f_nor[++i])
		ft_putchar(f_nor[i]);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	current;
	char			*string;

	string = (char *)addr;
	current = size;
	if (size == 0)
		return (0);
	while (current > 16)
	{
		print_hexa((long int) string, 16);
		write(1, ": ", 2);
		ft_print_line(string, 16, 0);
		string += 16;
		current -= 16;
	}
	print_hexa((long int) string, 16);
	write(1, ": ", 2);
	ft_print_line(string, current - 1, 0);
	write(1, "\n", 1);
	return (addr);
}
/*
int	main(void)
{
	char string[57] = "Fuck la \no\rminnette et la moulinette et la randominnette";
	ft_print_memory(string, 2000);
}*/
