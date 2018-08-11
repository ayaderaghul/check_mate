#include "../check_mate.h"
int main()
{
    profile *king = NULL;
    profile **kings = &king;
    profile *attacker = NULL;
    profile **attackers = &attacker;
    *kings = create_profile('K', 1, 1);
//	*attackers = create_profile('P',2,2);
//	add_profile(attackers,'R',0,0);
    printf("%d\n", check_mate(kings, attackers, 2));
    return 0;
}
