#include "../check_mate.h"

int main()
{
    profile *king = NULL;
    profile **kings = &king;

    profile *attacker = NULL;
    profile **attackers = &attacker;

	char str[] = ".K";
	char array[4] = {'P','B','R','Q'};
    int k;
    int j;
	int i;
	i = 1;

    j = 0;

    while(str[j])
    {
        k = 0;
		while (k < 4)
        {
            if (str[j] == 'K')
			{
				*kings = create_profile('K', j, i);
//add_profile(kings, 'K', j, i);
				break ;
			}
            if (str[j] == array[k])
            {
                add_profile(attackers, str[j], j, i);
                break ;
            }
            ++k;
        }
        ++j;
    }


//    *attackers = create_profile('P', 2, 1);
//    add_profile(attackers, 'Q', 0, 0);

	int k_x = (*kings)->x;
	int k_y = (*kings)->y;

	printf("x %d, y %d\n", k_x, k_y);

	if(check_mate(kings, attackers, 2))
		write(1,"s",1);
	write(1,"f",1);
//	free(*kings);
/*
	while (*attackers)
	{
		free(*attackers);
		*attackers = (*attackers)->next;
	}
*/
//    print_profile(kings);
//    print_profile(attackers);
    return 0;
}
