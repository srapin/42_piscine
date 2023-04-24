/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:35:40 by srapin            #+#    #+#             */
/*   Updated: 2022/10/03 05:00:49 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	size_t	len_src;
	char	*cpy;

	len_src = 0;
	while (src[len_src])
		len_src++;
	cpy = (char *) malloc(len_src + 1);
	ft_strcpy(cpy, src);
	return (cpy);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	char	*c;
	char	*truc;
	(void)	ac;
	c = av[1];
	truc = ft_strdup(c);
	printf("La copie contient : %s\n", truc);
	printf("%s", truc);
	free(truc);
}
*/
