/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:48:10 by srapin            #+#    #+#             */
/*   Updated: 2022/10/02 19:39:04 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef TOOLS_H
#define TOOLS_H

#include <stdlib.h>

#include <stdio.h>

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>



char	**ft_split(char *str, char *charset);

typedef struct elem_dict
{
	char	*nb;
	char	*trad;
	struct elem_dict	*next;
	struct elem_dict	*prev;
}	elem_dict;

extern int malloc_cpt;

int	find_and_print(char *nb, elem_dict *dict);

struct elem_dict	*get_first(elem_dict *dict);

struct elem_dict	*get_last(elem_dict *dict);

struct elem_dict	*init(elem_dict *dict, char *nb, char *trad);

void	free_dict(elem_dict	*dict);

void	set_prev(elem_dict *dict, elem_dict *prev);

void	set_next(elem_dict *dict, elem_dict *next);

void	print_dict(elem_dict *dict);

int	convert(char *nbr, elem_dict *dict);

long long	ft_atoi_dict(char *str);

int	count_words(char *str, char *charset);

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	ft_strlen(char *str);

char	*ft_itoa(long long int long_nbr);

struct elem_dict	*construct_dict(char *file);

char	*ft_strstr(char *str, char *to_find);

void	print_elem(elem_dict	*dict);

void	ft_memset(char *ptr, int val, int size);

char	*ft_strcat(char *dest, char *src);

long long int	ft_pow(int a, int b);

#endif
