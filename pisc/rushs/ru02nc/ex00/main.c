/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:21:15 by srapin            #+#    #+#             */
/*   Updated: 2022/10/02 22:34:30 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include <stdio.h>

int main (int argc, char **argv)
{
	char	*str_nb;
	char	*file_dict;
	elem_dict	*dict;
	file_dict = "numbers.dict";

	str_nb = NULL;
	if (argc != 2 && argc != 3)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (argc == 2)
		str_nb = ft_itoa(ft_atoi_dict(argv[1]));
	else if (argc == 3)
	{
		str_nb = ft_itoa(ft_atoi_dict(argv[2]));
		file_dict = argv[1];
	}
	if (! str_nb)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	dict = construct_dict(file_dict); // passe dict en deuxieme arg de construct_file (doit malloc du coup...) pour que puisse retourner (-1) si a une erreur
	if (! dict)
	{
		free_dict(dict);
		return(-1);
	}
	convert(str_nb, dict);
	free_dict(dict);
	return (0);
}