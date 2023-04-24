/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 04:48:32 by srapin            #+#    #+#             */
/*   Updated: 2022/10/05 05:36:36 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	main(int ac, char **av)
{
	int	to_read;
	int	i;
	int	map_to_treat;
	char	*output;

	i = 0;
	if (ac == 1)
		to_read = 0;
	else
		to_read = 1;
	while (to_read < ac)
	{
		output = treat_input(to_read, av);
		ft_putstr(output);
		write(1, '\n', 1);
	}
	return (0);
}
