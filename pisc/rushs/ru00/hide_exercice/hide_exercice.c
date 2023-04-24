/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hide_exercice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:10:04 by pjay              #+#    #+#             */
/*   Updated: 2022/09/18 16:01:07 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	*ft_strcpy(char *dest, char *src)
{
	int	a;

	a = 0;
	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = src[a];
	return (dest);
}

int	get_char(int curc, int curl, int col, int line)
{
	if (curl == 0)
	{
		if (curc == 0)
			return (0);
		else if (curc == col - 1)
			return (1);
		else
			return (4);
	}
	else if (curl == line - 1)
	{
		if (curc == 0)
			return (2);
		else if (curc == col - 1)
			return (3);
		else
			return (4);
	}
	else if (curc == 0 || curc == col - 1)
		return (5);
	return (6);
}

void	hide_rush(int col, int line, int ex)
{
	char	caracters[5][7];
	int		curl;
	int		curc;
	int		car_pos;

	ft_strcpy(caracters[0], "oooo-| ");
	ft_strcpy(caracters[1], "/\\\\/** ");
	ft_strcpy(caracters[2], "AACCBB ");
	ft_strcpy(caracters[3], "ACACBB ");
	ft_strcpy(caracters[4], "ACCABB ");
	curl = 0;
	curc = 0;
	while (curl < line)
	{
		while (curc < col)
		{
			car_pos = get_char(curc, curl, col, line);
			ft_putchar(caracters[ex][car_pos]);
			curc++;
		}
		curc = 0;
		ft_putchar('\n');
		curl++;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' || str[i] == '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (sign * res);
}
