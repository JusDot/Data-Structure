#include "AvlTree.h"
#include "Util.h"
#include <stdio.h>

int main()
{
	
	freopen("test.txt", "r", stdin);
	AvlTree T = NULL;
	int num;
	while (scanf("%d", &num) != EOF)
	{
		T = insert(num, T);
	}
	print(T);
	printf("\n");
	return 0;
}