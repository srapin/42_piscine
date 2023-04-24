/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 09:12:21 by srapin            #+#    #+#             */
/*   Updated: 2022/09/25 21:08:11 by srapin           ###   ########.fr       */
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

int	main(int argv, char *argc[])
{
	int	i;

	i = 1;
	while (i < argv)
	{
		write(1, argc[i], ft_strlen(argc[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
