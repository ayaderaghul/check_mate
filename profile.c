/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   profile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 12:29:48 by lnguyen           #+#    #+#             */
/*   Updated: 2018/08/11 17:04:23 by lnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

profile *create_profile(char c, int i, int j)
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

void add_profile(profile **begin_list, char c, int i, int j)
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

void print_profile(profile **p)
{
    while (*p)
    {
        ft_putchar((*p)->c);
        ft_putchar((*p)->x + '0');
        ft_putchar((*p)->y + '0');
        *p = (*p)->next;
    }
}
