/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 08:40:45 by lnguyen           #+#    #+#             */
/*   Updated: 2018/08/11 11:16:32 by lnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"
#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i;
	i = 0;
	while (str[i])
		ft_putchar(i++);
	ft_putchar('\n');
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}


profile *create_profile(char *c, int i, int j)
{
	profile *new_elem;

	new_elem = (profile*)malloc(sizeof(profile));
	if (new_elem == NULL)
		return (NULL);
	new_elem->next = NULL;
	new_elem->c = c;
	new_elem->x = i;
	new_elem->y = j;
	
	return (new_elem);
}

void add_profile(t_list **begin_list, char *c, int i, int j)
{
	profile *new_elem;
	new_elem = create_profile(c, i, j);
	if (new_elem == 0)
		return ;
	if (&*begin_list == 0)
		return ;
	if(*begin_list)
		new_elem->next = *begin_list;
	*begin_list = new_elem;
}
char *scan(char *str, int i, char *king, char *attackers)
{
	char array[4];
	array = {'P','B','R','Q'};
	int k;
	int j;
	k = 0;
	j = 0;
	while(str[j])
	{
		while (k < 4)
		{
			if (c == 'K')
				*king = create_profile(c, j);
			if (c == array[k])
			{
				add_profile(attackers, c, i, j);
				break ;
			}
			++k;
		}
		++j;
	}
}

coordinate *create_coor(int i, int j)
{
	coordinate *new_elem;
	new_elem = (coordinate*)malloc(sizeof(coordinate));
	if (new_elem == NULL)
		return (NULL);
	new_elem->next = NULL;
	new_elem->x = i;
	new_elem->y = j;
	return (new_elem);
}

void add_coor(coordinate **begin_list, int i, int j)
{
	coordinate *new_elem;
	new_elem = add_coor(i, j);
	if (new_elem == 0)
		return ;
	if (&*begin_list == 0)
		return ;
	if (*begin_list)
		new_elem->next = *begin_list;
	*begin_list = new_elem;
}

int absolute(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}


coordinate **shifted_bishop_range(coordinate **begin_list, int x, int y, int l)
{
	int x_f = -x;
	int x_c = l - 1 - x;
	int y_f = -y;
	int y_c = l - 1 - y;
	
	int s_d = max(x_f, y_f);
	int e_d = min (x_c, y_c);
	
	int n;
	n = s_d;
    while (n <= e_d)
	{
		add_coor(begin_list, n, n);
		++n;
	}
	
	int s_u = min(absolute(x_f), absolute (y_c));
	int e_u = min(absolute(x_c), absolute(y_f));
	
	n = -s_u;
	while (n <= e_u)
	{
		add_coor(begin_list, n, -n);
		++n;
	}
	return (begin_list);
}

coordinate **pawn_range(int x, int y)
{
	coordinate **begin_list;
	begin_list = add_coor(begin_list, x - 1, y - 1);
	begin_list = add_coor(begin_list, x + 1, y - 1);
	return (begin_list);
}

int check_mate(char *king, char *attackers)
{
	

int main(int ac, char **av)
{
	int i;
	int l;
	char *king;
	char *attackers;

	if (ac < 2)
		ft_putchar('\n');
	l =	ft_strlen(av[1]);
	i = 1;
	while (i < ac)
	{
		scan(av[i], i - 1, king, attackers);
		++i;
	}
	if (check_mate(king, attackers))
		ft_putstr("Success.");
	else
		ft_putstr("Failure.");
	return(0);
}
