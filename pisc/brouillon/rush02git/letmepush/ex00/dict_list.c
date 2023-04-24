/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:16:51 by srapin            #+#    #+#             */
/*   Updated: 2022/10/02 22:33:09 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "tools.h"

int	find_and_print(char *nb, elem_dict *dict)
{
	//print_dict(dict);
	printf("%s", nb);
	dict = get_first(dict);
	while (dict->next != NULL)
	{
		if (ft_strstr(dict->nb, nb) != 0)
		{
			write (1, dict->trad, ft_strlen(dict->trad));
			return (0);
		}
		dict = dict->next;
	}
	return (1); //nbr not in dict
}

void	set_prev(elem_dict *dict, elem_dict *prev)
{
	if (dict != NULL)
		dict->prev = prev;
}

void	set_next(elem_dict *dict, elem_dict *next)
{
	if (dict != NULL)
		dict->next = next;
}

struct elem_dict *get_first(elem_dict *dict)
{
	if (dict==NULL)
		return NULL;
	while (dict->prev != NULL && dict->prev->next != NULL)
	{
		//print_elem(dict);
		dict = dict->prev;
	}
	return dict;
}

struct elem_dict *get_last(elem_dict *dict)
{
	while (dict->next != NULL)
		dict = dict->next;
	return dict;
}

struct elem_dict	*init(elem_dict *dict, char *nb, char *trad)
{
	int nb_len;
	int trad_len;

	nb_len = ft_strlen(nb);
	trad_len = ft_strlen(trad);
	dict = malloc(sizeof(elem_dict));
	dict->nb=malloc(sizeof(char) * (nb_len + 1));
	if (dict->nb == NULL)
		return (NULL);
	dict->trad=malloc(sizeof(char) * (trad_len + 1));
	if (dict->trad == NULL)
	{
		free(dict->nb);
		return (NULL);
	}
	ft_strncpy(dict->nb, nb, nb_len);
	ft_strncpy(dict->trad, trad, trad_len);
	return (dict);
}

void  free_one_dict(elem_dict	*dict)
{
	free(dict->nb);
	free(dict->trad);
	free(dict);
}

void free_dict(elem_dict	*dict)
{
	dict = get_first(dict);
	while (dict->next != NULL)
	{
		dict = dict->next;
		free_one_dict(dict->prev);
	}
	free_one_dict(dict);
}

#include <stdio.h>  //to_del

void	print_elem(elem_dict	*dict)
{
	if (dict == NULL)
		return;
	printf("-------- \n");
	printf("nb = %s\n", dict->nb);
	printf("trad = %s\n", dict->trad);
	if (dict->prev != NULL)
		printf("is backlinked_with %s\n", dict->prev->nb);
	if (dict->next != NULL)
		printf("is forlinked_with %s\n", dict->next->nb);
	printf("------------\n");
}
void print_dict(elem_dict	*dict)
{
	int i=0;

	if (dict == NULL)
		return;
	dict = get_first(dict);
	while (dict->next != NULL)
	{
		print_elem(dict);
		i++;
		dict = dict->next;
	}
}