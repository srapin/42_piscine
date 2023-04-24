/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 05:54:59 by srapin            #+#    #+#             */
/*   Updated: 2022/10/06 06:10:30 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_swap(t_list *prev, t_list *current, t_list *next)
{
	if (prev)
		prev->next = next;
	current->next = next->next;
	next->next = current;
}

void ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*first;
	t_list	*prev;

	prev = NULL;
	first = begin_list;
	while (begin_list->next)
	{
		if ((*cmp) (begin_list->data, begin_list->next->data) > 0)
		{	
			ft_list_swap(prev, begin_list, begin_list->next);
			prev = NULL;
			begin_list = first;
		}
		else
		{
			prev = begin_list;
			begin_list = begin_list->next;
		}
	}
}
