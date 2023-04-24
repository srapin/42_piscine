/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_dict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:45:35 by srapin            #+#    #+#             */
/*   Updated: 2022/10/02 22:28:21 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"


char	*get_str_dict(char *file)
{
	int	fd;
	int	check;
	int	buff_size;
	char	*str_dict;
	char	c[1];

	fd = open(file, O_RDONLY);
	buff_size = 0;
	if (fd < 0)
		return 0;
	check = read(fd, c, 1);
	if (check < 0)
		return 0;
	while (check)
	{
		if (check == -1)
			return (0);
		check = read(fd, c, 1);
		buff_size++;
	}
	close(fd);
	str_dict = malloc((buff_size + 1) * sizeof(char));
	if (str_dict == 0)
		return 0;
	fd = open(file, O_RDONLY);
	read(fd, str_dict, buff_size);
	close(fd);
	str_dict[buff_size] = '\0';
	return (str_dict);
}


struct elem_dict	*parse(char *line)
{
	long long int	nbr;
	char	**args;
	char	**trad;
	char	*nb;
	elem_dict	*dict;

	dict = 0;
	args = ft_split(line, ":");
	if (args == 0)
		return (0);
	nbr = ft_atoi_dict(args[0]);
	if (nbr < 0 || nbr > 4294967295)
		return (0);
	nb = ft_itoa(nbr);
	if (nb == NULL)
	{
		free(args);
		return NULL;
	}
	trad = ft_split(args[1], " \t\v\n\f\r");
	if (trad == 0)
	{
		free(nb);
		free(args);
		return 0;
	}
	dict = init(dict, nb, trad[0]);
	free(nb);
	free(trad);
	free(args);
	return (dict);
}

struct elem_dict	*construct_dict(char *file)
{
	char	*str_dict;
	char	**lines;
	int	i;
	int	lines_len;
	elem_dict	*prev;
	elem_dict	*current;

	str_dict = get_str_dict(file);
	if (str_dict == 0)
		return (0);
	lines = ft_split(str_dict, "\n");
	i=0;
	if (lines == NULL)
	{
		free(str_dict);
		return (0);
	}
	lines_len = count_words(str_dict, "\n");
	i = 0;
	prev = NULL;
	current = NULL;
	while (lines + i != NULL && i < lines_len)
	{
		current = parse(lines[i]);
		if (current != 0)
		{
			set_prev(current, prev);
			set_next(prev, current);
			prev = current;
		}
		i++;
	}
	free(lines);
	return (prev);
}
