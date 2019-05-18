#include "pch.h"
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int coins[100];
int soma;

int pd[100][50000];

int f(int item, int subtracter, int adder)
{
	if (item == n)
		return abs(subtracter - adder);

	if (pd[item][subtracter] != -1)
		return pd[item][subtracter];

	int resp = f(item + 1, subtracter, adder);
	
	if(subtracter - coins[item] >= soma/2)
		resp = min(resp, f(item + 1, subtracter - coins[item], adder + coins[item]));

	return pd[item][subtracter] = resp;
}

int main()
{
	freopen("Input.txt", "r", stdin);

	int T; scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		memset(pd, -1, sizeof pd);

		soma = 0;
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &coins[j]);
			soma += coins[j];
		}

		printf("%d\n", f(0, soma, 0));
	}
}
