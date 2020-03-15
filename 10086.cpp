#include "pch.h"

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

#define inf 10000000

int NCPC[35][25];
int BCEW[35][25];

int rods[35];
int dp[310][310][35];

int f(int index, int T1, int T2)
{
	if (index < 0) return 0;
	if(dp[index][T1][T2] != -1) return dp[index][T1][T2];

	int resp = inf;

	int m = rods[index];
	for (int i = 0; i <= m; i++)
		if (T1 >= i && T2 >= m - i)
			resp = min(resp, NCPC[index][i] + BCEW[index][m - i] + f(index - 1, T1 - i, T2 - (m - i)));

	return dp[index][T1][T2] = resp;
}

stack<int> resp;
void rec(int index, int T1, int T2)
{
	if (index < 0) return;

	int m = rods[index];
	for (int i = 0; i <= m; i++)
		if (T1 >= i && T2 >= m - i)
			if (dp[index][T1][T2] == NCPC[index][i] + BCEW[index][m - i] + f(index - 1, T1 - i, T2 - (m - i)))
			{
				resp.push(i);
				return rec(index - 1, T1 - i, T2 - (m - i));
			}

}

int main()
{
	int T1, T2;
	while (scanf("%d %d", &T1, &T2) && (T1 || T2))
	{
		memset(dp, -1, sizeof(dp));
		

		int n; scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			int m; scanf("%d", &m);
			rods[i] = m;

			NCPC[i][0] = 0;
			BCEW[i][0] = 0;

			for (int j = 1; j <= m; j++)
				scanf("%d", &NCPC[i][j]);
			for (int j = 1; j <= m; j++)
				scanf("%d", &BCEW[i][j]);
		}

		printf("%d\n", f(n - 1, T1, T2));

		while (!resp.empty())
			resp.pop();

		rec(n - 1, T1, T2);

		if (!resp.empty())
		{
			printf("%d", resp.top());
			resp.pop();
		}

		while (!resp.empty())
		{
			printf(" %d", resp.top());
			resp.pop();
		}
		printf("\n\n");
	}
}