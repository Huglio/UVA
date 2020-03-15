#include "pch.h"

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>

using namespace std;

#define inf 10000000

int pd[60][60];
int vet[1010];

int f(int left, int right)
{
	if (right == left + 1) return 0;
	if (pd[left][right] != -1) return pd[left][right];

	int resp = inf;
	for (int i = left + 1; i < right; i++)
		resp = min(resp, f(left, i) + f(i, right) + (vet[right] - vet[left]));

	return pd[left][right] = resp;
}

int main()
{
	int l;
	while (scanf("%d", &l) && l)
	{
		memset(pd, -1, sizeof(pd));

		int n; scanf("%d", &n);

		vet[0] = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &vet[i]);
		vet[n + 1] = l;

		printf("The minimum cutting is %d.\n", f(0, n + 1));
	}
}