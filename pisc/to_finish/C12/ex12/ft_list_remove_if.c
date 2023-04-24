/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 05:44:45 by srapin            #+#    #+#             */
/*   Updated: 2022/10/06 05:48:40 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*prev;

	prev = NULL;
	while (begin_list->next)
	{
		if ((*cmp)(begin_list->data, data_ref) == 0)
		{
			prev->next = begin_list->next;
			(*free_fct) (begin_list->data);
			free(begin_list);
		}
		begin_list = begin_list->next;
		prev = begin_list;
	}
}
