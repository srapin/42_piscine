/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 03:50:35 by srapin            #+#    #+#             */
/*   Updated: 2022/10/06 19:35:18 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*last;
	t_list	*to_add;

	last = ft_list_last(*begin_list);
	to_add = ft_create_elem(data);
	last->next = to_add;
}

/*
#include <stdio.h>
t_list	*ft_create_elem(void *data)
{
	t_list	*lst;

	lst = malloc(sizeof(struct s_list));
	lst->data = data;
	lst->next = NULL;
	return (lst);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*lst;

	lst = ft_create_elem(data);
	lst->next = *begin_list;
	*begin_list = lst;
}


int main() {
	char *c;
	c = "salut";
	char *c2;
	c2 = "bonjour";
	t_list	*lst;

	lst = ft_create_elem(c);

	ft_list_push_back(&lst, c2);
	while (lst)	
	{
		printf("%s", lst->data);
		lst = lst->next;
	}	
	return 0;
}
*/
