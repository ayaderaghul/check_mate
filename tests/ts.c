#include "../check_mate.h"
int main()
{
    profile *king = NULL;
    profile *attacker = NULL;
    profile **kings = &king;
    profile **attackers = &attacker;
    scan("..",0,kings,attackers);
	scan(".K",1,kings,attackers);
//	scan("..P.",2,kings, attackers);
//	scan("....",3,kings,attackers);
	print_profile(kings);
	ft_putchar('\n');
	print_profile(attackers);
	ft_putchar('\n');

	int k_x;
	k_x = (*kings)->x;
	write(1,"before check mate\n", 100);
	if (k_x == 1)
		k_x = k_x + 1 - 1;
	if (check_mate(kings, attackers, 2) == 1)
		write(1, "success", 50);
	else
		write(1, "fail", 50);

    return 0;
}

