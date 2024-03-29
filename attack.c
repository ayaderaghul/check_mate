/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 12:33:12 by lnguyen           #+#    #+#             */
/*   Updated: 2018/08/11 17:09:46 by lnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

int shifted_bishop_attack(int x, int y, int l, int k_x, int k_y)
{
    int x_f = -x;
    int x_c = l - 1 - x;
    int y_f = -y;
    int y_c = l - 1 - y;

    int s_d = max(x_f, y_f);
    int e_d = min (x_c, y_c);

    k_x = k_x - x;
    k_y = k_y - y;

    int n;
    n = s_d;
    while (n <= e_d)
    {
        if (k_x == n && k_y == n)
            return (1);
        ++n;
    }

    int s_u = min(absolute(x_f), absolute (y_c));
    int e_u = min(absolute(x_c), absolute(y_f));

    n = -s_u;
    while (n <= e_u)
    {
        if (k_x == n && k_y == -n)
            return (1);
        ++n;
    }
    return (0);
}

int pawn_attack(int x, int y, int k_x, int k_y)
{
    if ((k_x == x - 1 && k_y == y - 1) || (k_x == x + 1 && k_y == y - 1))
        return (1);
    return (0);
}


int rook_attack(int x, int y, int l, int k_x, int k_y)
{
    int n;
    n = 0;
    while (n <= l - 1)
    {
        if ((k_x == n && k_y == y) || (k_x == x && k_y == n))
            return (1);
        ++n;
    }
    return (0);
}
