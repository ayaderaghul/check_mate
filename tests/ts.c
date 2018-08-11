#include "../check_mate.h"
int main()
{
    profile *king = NULL;
    profile *attacker = NULL;
    profile **kings = &king;
    profile **attackers = &attacker;
    scan("R...",0,kings,attackers);
	scan(".K..",1,kings,attackers);
	scan("..P.",2,kings, attackers);
	scan("....",3,kings,attackers);
	print_profile(kings);
	ft_putchar('\n');
	print_profile(attackers);
	ft_putchar('\n');
	if (check_mate(kings, attackers, 4) == 1)
		write(1, "success", 50);
	else
		write(1, "fail", 50);

    return 0;
}

