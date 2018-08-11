/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 08:41:38 by lnguyen           #+#    #+#             */
/*   Updated: 2018/08/11 12:50:11 by lnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef CHECK_MATE_H
# define CHECK_MATE_H

#include <stdlib.h>
#include <unistd.h>

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

void ft_putchar(char c);
void ft_putstr(char *str);
int ft_strlen(char *str);
profile *create_profile(char c, int i, int j);
void add_profile(profile **begin_list, char c, int i, int j);
void printf_profile(profile **p);
coordinate *create_coor(int i, int j);
void add_coor(coordinate **begin_list, int i, int j);
int absolute(int a);
int min(int a, int b);
int max(int a, int b);

void scan(char *str, int i, profile **king, profile **attackers);




int shifted_bishop_attack(int x, int y, int l, int k_x, int k_y);
int pawn_attack(int x, int y, int k_x, int k_y);
int rook_attack(int x, int y, int l, int k_x, int k_y);

int check_mate(profile **king, profile **attackers, int l);

#endif
