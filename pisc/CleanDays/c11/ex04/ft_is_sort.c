/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:10:07 by srapin            #+#    #+#             */
/*   Updated: 2022/10/06 14:57:52 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	flag_asc;
	int	flag_desc;

	i = 0;
	flag_asc = 1;
	flag_desc = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			flag_asc = 0;
		if (f(tab[i], tab[i + 1]) > 0)
			flag_desc = 0;
		i++;
	}
	if (flag_asc || flag_desc)
		return (1);
	return (0);
}

/*
int	test(int a, int b)
{
	return (a - b);
}



int	main(int ac, char ** av)
{	
	int min;
	int max;
	int tab;
//	min = atoi(av[1]);
//	max = atoi(av[2]);
	int j[] = {1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 6, 6, 7};
	printf("%d", ft_is_sort( j, 12, &test));
	return (0);


}*/
