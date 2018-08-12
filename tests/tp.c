#include "../check_mate.h"
int main()
{
	profile *king = NULL;
	profile **kings = &king;
	*kings = create_profile('K',1,1);
	free(*kings);
	return 0;
}
