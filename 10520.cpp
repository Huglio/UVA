#include "pch.h"

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define inf 1e9
#define ll long long int

ll dp[25][25];
int n;

ll f(int i, int j)
{
	if (dp[i][j] != -1) return dp[i][j];

	if (i < j)
	{
		ll resp = 0;
		for (int k = i; k < j; k++)
			resp = max(resp, f(i, k) + f(k + 1, j));

		return dp[i][j] = resp;
	}
	else
	{
		ll a, b;

		if (i == n)
			a = 0;
		else
		{
			a = 0;
			for (int k = i + 1; k <= n; k++)
				a = max(a, f(k, 1) + f(k, j));
		}

		if (j == 0)
			b = 0;
		else
		{
			b = 0;
			for (int k = 1; k < j; k++)
				b = max(b, f(i, k) + f(n, k));
		}

		return dp[i][j] = a + b;
	}
}

int main()
{
	int a;
	while (scanf("%d %d", &n, &a) != EOF)
	{
		memset(dp, -1, sizeof(dp));
		dp[n][1] = a;
	
		printf("%d\n", f(1, n));
	}
}