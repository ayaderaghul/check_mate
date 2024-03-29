#include "check_mate.h"

int main(int ac, char **av)
{
    profile *king = NULL;
    profile **kings = &king;
    profile *attacker = NULL;
    profile **attackers = &attacker;

	if (ac < 2)
	{
		write(1,"\n",1);
		return 0;
	}
	int l;
	l = ft_strlen(av[1]);
	int i;
	i = 1;
	while (i < ac)
	{
		scan(av[i], i-1 ,kings, attackers);
		++i;
	}
	if(check_mate(kings, attackers, l))
		write(1,"Success\n",8);
	else
		write(1,"Fail\n",5);
	free(*kings);
	while(*attackers)
	{
		free(*attackers);
		*attackers = (*attackers)->next;
	}
	return 0;
}
