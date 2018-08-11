/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 12:49:36 by lnguyen           #+#    #+#             */
/*   Updated: 2018/08/11 18:10:13 by lnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

int check_mate(profile **kings, profile **attackers, int l)
{
	write(1,"in check mate\n",14);
    int k_x = (*kings)->x;
    int k_y = (*kings)->y;
	write(1,"before loop\n",12);

    while(*attackers)
    {
		write(1,"in loop\n",10);
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
