#include "../check_mate.h"

int main()
{
    profile *king = NULL;
    profile **kings = &king;

    profile *attacker = NULL;
    profile **attackers = &attacker;

    *kings = create_profile('K', 1, 1);

    *attackers = create_profile('P', 2, 1);
    add_profile(attackers, 'Q', 0, 0);

	int k_x = (*kings)->x;
	int k_y = (*kings)->y;

	printf("x %d, y %d\n", k_x, k_y);
	free(*kings);
	while (*attackers)
	{
		free(*attackers);
		*attackers = (*attackers)->next;
	}
//    print_profile(kings);
//    print_profile(attackers);
    return 0;
}
