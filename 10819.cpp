#include "pch.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

#define gasto m - money

int n, m;
int value[110];
int weight[110];
int pd[110][10210];

int f(int index, int money)
{
	if (index >= n) return 0;
	if (money <= 0) return 0;
	if (money <= 200 && (gasto + weight[index] <= 2000)) return 0;

	if (pd[index][money] != -1) return pd[index][money];

	int resp = f(index + 1, money);
	//printf("gasto + weight[index] %d\n", gasto + weight[index]);
	//printf("money %d weight[index] %d\n", money, weight[index]);
	if (money - 200 >= weight[index] || (gasto + weight[index] > 2000 && money >= weight[index]))
		resp = max(resp, value[index] + f(index + 1, money - weight[index]));
	
	return pd[index][money] = resp;
}

int main()
{
	while (scanf("%d %d", &m, &n) != EOF)
	{
		memset(pd, -1, sizeof(pd));

		for (int i = 0; i < n; i++)
			scanf("%d %d", &weight[i], &value[i]);
		m = m + 200;
		printf("%d\n", f(0, m));
	}
}