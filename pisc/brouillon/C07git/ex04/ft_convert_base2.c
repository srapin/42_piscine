/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:35:47 by srapin            #+#    #+#             */
/*   Updated: 2022/09/30 14:38:14 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_jpp
{
	int			base_size;
	int			index;
	long int	nb;
	int			sign;
	int			nb_lenght;
	int			i;
}				t_jpp;

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i;
		while (base[j])
		{
			if (base[j] == '+' || base[j] == '-'
				|| (base[i] == base[j] && i != j)
				|| base[j] == ' ' || base[j] == '\t' || base[j] == '\n'
				|| base[j] == '\v' || base[j] == '\f' || base[j] == '\r')
				return (-1);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (-1);
	return (i);
}

int	ft_strstr(char *str, char to_find)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}

void	initialize(char *str, char *base, t_jpp *pffff)
{
	int		i;
	t_jpp	pfff;

	i = 0;
	pfff.nb = 0;
	pfff.base_size = check_base(base);
	pfff.nb_lenght = 0;
	pfff.sign = 1;
	if (pfff.base_size < 2)
	{
		*pffff = pfff;
		return ;
	}
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| base[i] == '\f' || base[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pfff.sign *= -1;
		i++;
	}
	pfff.i = i;
	*pffff = pfff;
}

int	ft_atoi_base(char *str, char *base)
{
	t_jpp	*pffff;
	t_jpp	pfff;

	pffff = &pfff;
	initialize(str, base, pffff);
	if (pfff.base_size < 2)
		return (0);
	pfff.index = ft_strstr(base, str[pfff.i]);
	while (ft_strstr(base, str[pfff.i + pfff.nb_lenght]) >= 0)
		pfff.nb_lenght++;
	while (pfff.nb_lenght > 0)
	{
		pfff.index = ft_strstr(base, str[pfff.i]);
		pfff.nb_lenght--;
		pfff.nb = pfff.nb * pfff.base_size + pfff.index;
		pfff.i++;
	}
	return (pfff.nb * pfff.sign);
}
