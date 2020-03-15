#include "pch.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int N, x, T, K;

int favour[210];
int price[210];

int pd[210][20000][25];

int roundup(int x)
{
	if (x % 10)
		return x - (x % 10) + 10;
	return x;
}

int f(int index, int sum, int ordered)
{
	if (index >= K) return 0;
	if (ordered >= 2 * (N + 1)) return 0;
	if (pd[index][sum][ordered] != -1) return pd[index][sum][ordered];

	int resp = f(index + 1, sum, ordered);

	int nsum = sum + (price[index]);
	if (roundup(nsum) <= x)
		resp = max(resp, favour[index] + f(index + 1, nsum, ordered + 1));

	return pd[index][sum][ordered] = resp;
}

int main()
{
	freopen("Input.txt", "r", stdin);

	while (scanf("%d %d %d %d", &N, &x, &T, &K) && (N || x || T || K))
	{
		memset(pd, -1, sizeof(pd));

		x = x * (N + 1);
		K = K * 2;

		for (int i = 0; i < K; i += 2)
		{
			scanf("%d", &price[i]); price[i + 1] = price[i] = (price[i] * 10) + price[i];
			scanf("%d", &favour[i]);
			for (int j = 0; j < N; j++)
			{
				int x; scanf("%d", &x);
				favour[i] = favour[i] + x;
			}
			favour[i + 1] = favour[i];
		}

		/*for (int i = 0; i < K; i += 2)
			printf("%4d ", price[i]);
		printf("\n");
		for (int i = 0; i < K; i += 2)
			printf("%4d ", favour[i]);
		printf("\n");*/

		x = x * 10;
		T = T * 10;
		
		//printf("Podem gastar BRUTO: %d\n", x);
		
		int TeaCharge = ((N + 1) * T) + ((N + 1) * T / 10);

		//printf("Podem gastar: %d\n", x - TeaCharge);
		//printf("Favour: %d\n", f(0, TeaCharge, 0));
		printf("%.2f\n", f(0, TeaCharge, 0) / (float)(N + 1));
	}
}