/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 04:02:57 by srapin            #+#    #+#             */
/*   Updated: 2022/10/06 19:34:11 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*to_free;

	while (begin_list->next)
	{
		to_free = begin_list;
		begin_list = begin_list->next;
		free_fct(to_free->data);
		free(to_free);
	}
	free_fct(begin_list->data);
	free(begin_list);
}
