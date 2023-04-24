/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 03:32:13 by srapin            #+#    #+#             */
/*   Updated: 2022/10/06 18:46:21 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*lst;

	lst = malloc(sizeof(struct s_list));
	lst->data = data;
	lst->next = NULL;
	return (lst);
}
/*
int main() {
  char *c;
  c = "salut";
t_list	*lst;

 lst = ft_create_elem(c);
  printf("%s", lst->data );
  return 0;
}
*/
