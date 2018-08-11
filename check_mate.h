/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 08:41:38 by lnguyen           #+#    #+#             */
/*   Updated: 2018/08/11 15:53:52 by lnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MATE_H
# define CHECK_MATE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct prof
{
	struct prof *next;
	char c;
	int x;
	int y;
} profile;

void ft_putchar(char c);
void ft_putstr(char *str);
int ft_strlen(char *str);
profile *create_profile(char c, int i, int j);
void add_profile(profile **begin_list, char c, int i, int j);
void print_profile(profile **p);

int absolute(int a);
int min(int a, int b);
int max(int a, int b);

void scan(char *str, int i, profile **king, profile **attackers);




int shifted_bishop_attack(int x, int y, int l, int k_x, int k_y);
int pawn_attack(int x, int y, int k_x, int k_y);
int rook_attack(int x, int y, int l, int k_x, int k_y);

int check_mate(profile **king, profile **attackers, int l);

#endif
