#include "pch.h"
#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

int n;

int v[1000];
int wt[1000];

int pd[1010][40];

int f(int item, int left)
{
	if (item == n)
		return 0;

	if (pd[item][left] != -1)
		return pd[item][left];

	int resp = f(item + 1, left);

	if (left - wt[item] >= 0)
		resp = max(resp, f(item + 1, left - wt[item]) + v[item]);

	return pd[item][left] = resp;
}

int main()
{
	freopen("Input.txt", "r", stdin);

	int T; scanf("%d", &T);

	for (int k = 0; k < T; k++)
	{
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &v[i], &wt[i]);
		}

		int G; scanf("%d", &G);

		int sum = 0;
		for (int i = 0; i < G; i++)
		{
			memset(pd, -1, sizeof pd);

			int x; scanf("%d", &x);
			sum += f(0, x);
		}

		printf("%d\n", sum);
	}
}