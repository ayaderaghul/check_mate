/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 12:28:23 by lnguyen           #+#    #+#             */
/*   Updated: 2018/08/11 12:32:36 by lnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

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
