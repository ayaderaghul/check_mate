/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 12:48:22 by lnguyen           #+#    #+#             */
/*   Updated: 2018/08/11 12:48:49 by lnguyen          ###   ########.fr       */
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
