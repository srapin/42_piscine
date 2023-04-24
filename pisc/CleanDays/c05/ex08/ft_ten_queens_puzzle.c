/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 01:46:56 by srapin            #+#    #+#             */
/*   Updated: 2022/09/28 23:38:37 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct s_queen
{
	int	current;
	int	poss[10];	
}	t_queen;

t_queen	print_tab42makenewqueen0to9(t_queen *queens, int k)
{
	int		i;
	char	c;
	t_queen	queen;
	int		j;

	if (k == 42)
	{
		i = 0;
		while (i < 10)
		{
			c = queens[i].current + '0';
			write(1, &c, 1);
			i++;
		}
		write(1, "\n", 1);
		return (queens[0]);
	}
	j = -1;
	while (j++ < 10)
		queen.poss[j] = -1;
	queen.current = -1;
	return (queen);
}

int	poss_size(t_queen queen)
{
	int	i;
	int	cmp;

	i = 0;
	cmp = 0;
	while (i < 10)
	{
		if (queen.poss[i] > 0)
			cmp++;
		i++;
	}
	return (cmp);
}

void	find_possibilities(t_queen *queens, int queen)
{
	int	dist;
	int	other_queen;
	int	i;

	other_queen = 0;
	dist = queen;
	i = 0;
	while (i < 10)
	{
		queens[queen].poss[i] = 1;
		i++;
	}
	while (dist > 0)
	{
		if (dist > 0 && (queens[other_queen].current >= 0) && queen != 0)
		{
			if (queens[other_queen].current + dist < 10)
				queens[queen].poss[queens[other_queen].current + dist] = -1;
			if (queens[other_queen].current - dist >= 0)
				queens[queen].poss[queens[other_queen].current - dist] = -1;
			queens[queen].poss[queens[other_queen].current] = -1;
		}
		other_queen++;
		dist = queen - other_queen;
	}
}

void	explore_possibilitie(t_queen *queens, int queen, int *counter)
{
	int	i;

	i = 0;
	find_possibilities(queens, queen);
	while (i < 10)
	{
		if (queens[queen].poss[i] == 1)
		{
			queens[queen].current = i;
			if (queen + 1 != 10)
			{
				explore_possibilitie(queens, queen + 1, counter);
			}
			else
			{
				print_tab42makenewqueen0to9(queens, 42);
				*counter = *counter + 1;
			}
		}
		i = i + 1;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		ct;
	int		i;
	t_queen	queens[10];
	t_queen	queen;

	ct = 0;
	i = 0;
	while (i < 10)
	{
		queen = print_tab42makenewqueen0to9(queens, i);
		queens[i] = queen;
		i++;
	}
	explore_possibilitie(queens, 0, &ct);
	return (ct);
}
/*
#include <stdio.h>
int	main()
{
	ft_ten_queens_puzzle();
//	printf("%d", ft_ten_queens_puzzle());
}
*/
