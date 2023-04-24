/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:26:28 by srapin            #+#    #+#             */
/*   Updated: 2022/09/22 01:03:19 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] > s2[i])
		{
			return (1);
		}
		if (s1[i] < s2[i])
		{
			return (-1);
		}
		i++;
	}
	if (i == n)
		return (0);
	if (s1[i] && !s2[i])
		return (1);
	if (!s1[i] && s2[i])
		return (-1);
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	len_to_find;

	i = -1;
	len_to_find = ft_strlen(to_find);
	if (!*to_find)
		return (str);
	while (str[++i])
		if (ft_strncmp(str + i, to_find, len_to_find) == 0)
			return (str + i);
	return (0);
}
