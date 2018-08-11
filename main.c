/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 08:40:45 by lnguyen           #+#    #+#             */
/*   Updated: 2018/08/11 12:50:22 by lnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

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
