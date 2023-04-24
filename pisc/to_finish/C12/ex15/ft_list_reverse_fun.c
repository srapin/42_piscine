/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 06:12:09 by srapin            #+#    #+#             */
/*   Updated: 2022/10/06 06:13:41 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*prev;
	t_list	*suiv;

	prev = NULL;
	while (begin_list->next)
	{
		suiv = begin_list->next;
		begin_list->next = prev;
		prev = begin_list;
		begin_list = suiv;
	}
	begin_list = prev;
	return (begin_list);
}
