/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:22:27 by srapin            #+#    #+#             */
/*   Updated: 2022/10/06 15:05:27 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	do_plus(int a, int b);
void	do_min(int a, int b);
void	do_div(int a, int b);
void	do_mul(int a, int b);
void	do_mod(int a, int b);
int		ft_strstr(char *str, char *to_find);
int		ft_atoi(char	*str);

int	main(int ac, char **av)
{
	int		op;
	void	(*f[5])(int, int);

	f[0] = &do_plus;
	f[1] = &do_min;
	f[2] = &do_div;
	f[3] = &do_mul;
	f[4] = &do_mod;
	if (ac != 4)
		return (0);
	op = ft_strstr("+-/*%", av[2]);
	if (op == -1)
	{
		write(1, "0", 1);
		write(1, "\n", 1);
	}
	else
		f[op](ft_atoi(av[1]), ft_atoi(av[3]));
}
