/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 05:29:11 by srapin            #+#    #+#             */
/*   Updated: 2022/10/06 05:34:47 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list->next)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}
