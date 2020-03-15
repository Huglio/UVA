#include "pch.h"

#include <stdio.h>
#include <cstring>

using namespace std;

int pd[27][352][27];

int f(int index, int value, int last)
{
	//printf("entrou %d %d %d\n", index, value, last);

	if (value == 0 && index == 0) return 1;
	if (value < 0) return 0;
	if (index == 0) return 0;

	if (pd[index][value][last] != -1) return pd[index][value][last];

	int resp = 0;
	for (int i = 'a' + last; i <= 'z'; i++)
	{
		resp += f(index - 1, value - (i - 'a') - 1, (i - 'a') + 1);
	}

	return pd[index][value][last] = resp;
}

int main()
{
	memset(pd, -1, sizeof pd);

	int TC = 1;

	int l, s;
	while (scanf("%d %d", &l, &s) && (l || s))
	{
		if (l < 27 && s < 352)
			printf("Case %d: %d\n", TC++, f(l, s, 0));
		else
			printf("Case %d: 0\n", TC++);
	}
}