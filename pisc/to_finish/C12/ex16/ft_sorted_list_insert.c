/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 06:15:11 by srapin            #+#    #+#             */
/*   Updated: 2022/10/06 06:22:22 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*to_insert;

	to_insert = ft_create_elem(data);
	while (*begin_list->next && (*cmp)(begin_list->data, data) <= 0 && (*cmp)(begin_list->next->data, data) >=0 )
		begin_list = begin_list->next;
	to_insert->next = begin_list->next;
	begin_list->next = to_insert;
}
