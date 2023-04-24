/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 03:36:56 by srapin            #+#    #+#             */
/*   Updated: 2022/10/06 19:01:43 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*lst;

	lst = ft_create_elem(data);
	lst->next = *begin_list;
	*begin_list = lst;
}
/*
t_list	*ft_create_elem(void *data)
{
	t_list	*lst;

	lst = malloc(sizeof(struct s_list));
	lst->data = data;
	lst->next = NULL;
	return (lst);
}

int main() {
	char *c;
	c = "salut";
	char *c2;
	c2 = "bonjour";
	t_list	*lst;

	lst = ft_create_elem(c);

	ft_list_push_front(&lst, c2);	
	while(lst)
	{
		printf("%s", lst->data );
		lst = lst->next;
	}
	return 0;
}
*/
