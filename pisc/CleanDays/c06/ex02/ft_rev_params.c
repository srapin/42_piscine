/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:50:38 by srapin            #+#    #+#             */
/*   Updated: 2022/09/25 21:09:34 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int i, char *c[])
{
	i--;
	while (i > 0)
	{
		write(1, c[i], ft_strlen(c[i]));
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
