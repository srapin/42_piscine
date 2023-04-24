/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 04:16:35 by srapin            #+#    #+#             */
/*   Updated: 2022/10/06 19:54:56 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*prev;
	t_list	*suiv;
	t_list	*current;

	prev = NULL;
	current = *begin_list;
	while (current->next)
	{
		suiv = current->next;
		current->next = prev;
		prev = current;
		current = suiv;
	}
	begin_list = &prev;
}


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
t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*prev;
	t_list	*current;

	if (size <= 0)
		return (NULL);
	prev = ft_create_elem(strs[0]);
	i = 1;
	while (i < size)
	{
		current = ft_create_elem(strs[i]);
		current->next = prev;
		prev = current;
		i++;
	}
	return (current);
}


int main(int ac, char **av) {
	t_list	*lst;

	lst = ft_list_push_strs(ac, av);
	ft_list_reverse(&lst);

	while (lst)
	{
		printf("%s", lst->data);
		lst = lst->next;
	}
	return 0;
}


