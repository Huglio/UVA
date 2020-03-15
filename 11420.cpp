#include "pch.h"

#include <stdio.h>
#include <cstring>

using namespace std;

int n, s;
long long int pd[70][70][2];

long long int f(int index, int L, int last)
{
	if (index >= n) return L == 0 ? 1 : 0;
	if (L < 0) return 0;
	if (pd[index][L][last] != -1) return pd[index][L][last];

	long long int resp = f(index + 1, L, 0);

	if (last)
		resp += f(index + 1, L - 1, 1);
	else
		resp += f(index + 1, L, 1);

	return pd[index][L][last] = resp;
}

int main()
{ 
	while (scanf("%d %d", &n, &s) && (n >= 0 && s >= 0))
	{
		memset(pd, -1, sizeof(pd));
		printf("%lld\n", f(0, s, 1));
	}
}