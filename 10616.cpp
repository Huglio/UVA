#include "pch.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

#define ii pair<int, int>
#define inf 1000000

int n, d, m;
int vet[210];
long long int pd[210][30][20];

int soma(int a, int b)
{
	int resp = (a%d + b % d) % d;
	if (resp < 0)
		resp += d;
	return resp;
}

long long f(int index, int sum, int rest)
{
	if (rest == 0) return sum % d ? 0 : 1;
	if (index >= n) return 0;

	if (pd[index][sum][rest] != -1) return pd[index][sum][rest];

	long long  resp = f(index + 1, sum, rest);
	resp += f(index + 1, soma(sum, vet[index]), rest - 1);

	return pd[index][sum][rest] = resp;
}

int main()
{
	freopen("Input.txt", "r", stdin);

	int q;
	int set = 1;
	while (scanf("%d %d", &n, &q) && (n || q))
	{
		printf("SET %d:\n", set++);


		for (int i = 0; i < n; i++)
			scanf("%d", &vet[i]);

		for (int i = 1; i <= q; i++)
		{
			scanf("%d %d", &d, &m);

			memset(pd, -1, sizeof(pd));
			printf("QUERY %d: %lld\n", i, f(0, 0, m));
		}
	}
}