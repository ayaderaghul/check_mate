/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 08:41:38 by lnguyen           #+#    #+#             */
/*   Updated: 2018/08/10 16:48:04 by lnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef CHECK_MATE_H
# define CHECK_MATE_H

typedef struct prof
{
	struct prof *next;
	char* c;
	int x;
	int y;
} profile;

typedef struct coor
{
	struct coor *next;
	int x;
	int y;
} coordinate;




#endif
