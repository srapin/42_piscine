/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:07:43 by srapin            #+#    #+#             */
/*   Updated: 2022/10/06 02:29:08 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			cpt += 1;
		i++;
	}
	return (cpt);
}
/*

int	test(char * i)
{
	return (i[0] == 's');
}

int	main(int ac, char ** av)
{
	printf("%d", ft_count_if(av, ac, &test));
	return (0);
}
*/
