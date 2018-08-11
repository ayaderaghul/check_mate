/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 08:40:45 by lnguyen           #+#    #+#             */
/*   Updated: 2018/08/11 12:34:20 by lnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

void scan(char *str, int i, profile **king, profile **attackers)
{
	char array[4] = {'P','B','R','Q'};
	int k;
	int j;

	j = 0;


	while(str[j])
	{
		k = 0;
		while (k < 4)
		{
			if (str[j] == 'K')
				*king = create_profile('K', i, j);
			if (str[j] == array[k])
			{
				add_profile(attackers, str[j], i, j);
				break ;
			}
			++k;
		}
		++j;
	}
}


int check_mate(profile **king, profile **attackers, int l)
{
	int k_x = (*king)->x;
	int k_y = (*king)->y;

	while(*attackers)
	{
		if ((*attackers)->c == 'P')
		{
			int p_x = (*attackers)->x;
			int p_y = (*attackers)->y;
			if (pawn_attack(p_x, p_y, k_x, k_y))
				return (1);
		}
		if ((*attackers)->c == 'R')
		{
			int r_x = (*attackers)->x;
			int r_y = (*attackers)->y;
			if (rook_attack(r_x, r_y, l, k_x, k_y))
				return (1);
		}
		if ((*attackers)->c == 'B')
		{
			int b_x = (*attackers)->x;
			int b_y = (*attackers)->y;
			if (shifted_bishop_attack(b_x, b_y, l, k_x, k_y))
				return (1);
		}
		if ((*attackers)->c == 'Q')
		{
			int q_x = (*attackers)->x;
			int q_y = (*attackers)->y;
			if (shifted_bishop_attack(q_x, q_y, l, k_x, k_y))
				return (1);
			if (rook_attack(q_x, q_y, l, k_x, k_y))
				return (1);
		}
		*attackers = (*attackers)->next;
	}
	return (0);
}

int main(int ac, char **av)
{
	int i;
	int l;
	profile **king;
	profile **attackers;

	if (ac < 2)
	{
		ft_putchar('\n');
		return (0);
	}
	l =	ft_strlen(av[1]);
	i = 1;
	while (i < ac)
	{
		write(1,"before scan\n",50);
		scan(av[i], i - 1, king, attackers);
		write(1, "after scan\n", 50);
		print_profile(king);
		++i;
	}
	if (check_mate(king, attackers, l))
		ft_putstr("Success.");
	else
		ft_putstr("Failure.");
	return(0);
}
