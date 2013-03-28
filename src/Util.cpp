#include "Util.h"
#include <stdio.h>
#include <stdlib.h>

void error(char *msg)
{
	if (msg != NULL)
		printf("%s\n", msg);
	exit(0);
}

int max(int x, int y)
{
	if (x > y)
		return x;
	return y;
}