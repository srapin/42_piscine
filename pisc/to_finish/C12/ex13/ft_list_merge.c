/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 05:49:40 by srapin            #+#    #+#             */
/*   Updated: 2022/10/06 05:53:01 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}

void ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	end_list_1;

	end_list_1 = ft_list_merge(*begin_list1);
	end_list_1->next = begin_list2;
}
