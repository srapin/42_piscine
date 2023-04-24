/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:15:25 by srapin            #+#    #+#             */
/*   Updated: 2022/10/06 15:02:02 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(int nb);
void	ft_putstr(char *str);

void	do_plus(int a, int b)
{
	ft_putnbr(a + b);
	ft_putstr("\n");
}

void	do_min(int a, int b)
{
	ft_putnbr(a - b);
	ft_putstr("\n");
}

void	do_mul(int a, int b)
{
	ft_putnbr(a * b);
	ft_putstr("\n");
}

void	do_div(int a, int b)
{
	if (b == 0)
		ft_putstr("Stop : division by zero");
	else
		ft_putnbr(a / b);
	ft_putstr("\n");
}

void	do_mod(int a, int b)
{
	if (b == 0)
		ft_putstr("Stop : modulo by zero");
	else
		ft_putnbr(a % b);
	ft_putstr("\n");
}
