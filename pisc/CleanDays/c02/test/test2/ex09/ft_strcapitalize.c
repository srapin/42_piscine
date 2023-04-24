/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 02:56:33 by srapin            #+#    #+#             */
/*   Updated: 2022/09/19 01:42:58 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_numeric(char *str)
{
	if (str[0] < '0' || str[0] > '9')
		return (0);
	return (1);
}

int	ft_str_is_alpha(char *str)
{
	if (str[0] < 'A' || (str[0] > 'Z' && str[0] < 'a') || str[0] > 'z')
	{
		return (0);
	}
	return (1);
}

int	ft_str_is_lowercase(char *str)
{
	if (str[0] < 'a' || str[0] > 'z')
	{
		return (0);
	}
	return (1);
}

int	ft_str_is_uppercase(char *str)
{
	if (str[0] < 'A' || str[0] > 'Z')
	{
		return (0);
	}
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_str_is_lowercase(&str[i])
			&& (i == 0 || (!ft_str_is_alpha(&str[i - 1])
					&& !ft_str_is_numeric(&str[i - 1]))))
		{
		str[i] -= 32;
		}
		else if (i != 0 && (ft_str_is_alpha(&str[i])
				&& ft_str_is_uppercase(&str[i]))
			&& (ft_str_is_alpha(&str[i - 1])
				|| ft_str_is_numeric(&str[i - 1])))
		{
		str[i] += 32;
		}
		i++;
	}
	return (str);
}
