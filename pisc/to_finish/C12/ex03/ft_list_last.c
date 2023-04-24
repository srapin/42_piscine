/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 03:46:53 by srapin            #+#    #+#             */
/*   Updated: 2022/10/06 19:09:13 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
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

	ft_list_push_front(&lst, c2);	
	printf("%s", ft_list_last(lst)->data);
	return 0;
}
*/
