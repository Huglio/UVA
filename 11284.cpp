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

int MMask;

int p;
int lojas[20];
int preco[20];
int dist[60][60];
int pd[20][10000];

int tsp(int at, int mask)
{
	if (mask == MMask) return dist[lojas[at]][0];
	if (pd[at][mask] != -1) return pd[at][mask];

	int resp = inf;
	for (int i = 1; i < p; i++)
		if (at != i && (mask & (1 << i)) == 0)
			resp = min(resp, dist[lojas[at]][lojas[i]] + tsp(i, mask | (1 << i)));

	return pd[at][mask] = resp;
}

int main()
{
	freopen("Input.txt", "r", stdin);

	int TC; scanf("%d", &TC);

	while (TC--)
	{
		int n, m; scanf("%d %d", &n, &m); n++;

		for (int i = 0; i <= n; i++)
			for (int j = i; j <= n; j++)
				dist[i][j] = dist[j][i] = i == j ? 0 : inf;

		for (int i = 0; i < m; i++)
		{
			int x, y; float z; scanf("%d %d %f", &x, &y, &z);
			dist[x][y] = dist[y][x] = min(dist[x][y], (int)round(100 * z));
		}

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

		scanf("%d", &p); p++;
		lojas[0] = preco[0] = 0;

		int AllAmazon = 0;

		for (int i = 1; i < p; i++)
		{
			int x; float z; scanf("%d %f", &x, &z);
			lojas[i] = x;
			preco[i] = (int)round(100 * z);
			AllAmazon += preco[i];
		}

		MMask = (1 << p) - 1;

		int best = 0;

		for (int i = 1; i <= MMask; i += 2)
		{
			int custo = 0;
			for (int j = 1; j < p; j++)
				if ((i & (1 << j)) != 0)
					custo += preco[j];

			memset(pd, -1, sizeof(pd));
			custo += tsp(0, i);

			best = max(best, AllAmazon - custo);
		}

		if (best)
			printf("Daniel can save $%.2f\n", best/100.);
		else
			printf("Don't leave the house\n");
	}
}