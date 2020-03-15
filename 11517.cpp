#include "pch.h"

#include <stdio.h>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define inf 1000000
#define ll long long int

int main()
{
	int TC; scanf("%d", &TC);
	
	while (TC--)
	{
		int pd[10010][110];
		int cnt[10010][110];
		int vet[110];

		int s; scanf("%d", &s);
		int n; scanf("%d", &n);

		for (int i = 0; i < n; i++)
			scanf("%d", &vet[i]);

		for (int i = 0; i <= s; i++)
			for (int j = 0; j <= n; j++)
				pd[i][j] = inf;

		for (int i = 0; i <= s; i++)
			for (int j = 0; j <= n; j++)
				cnt[i][j] = inf;

		for (int i = 0; i <= s; i++)
			for (int j = 0; j < n; j++)
			{
				if (j)
				{
					pd[i][j] = pd[i][j - 1];
					cnt[i][j] = cnt[i][j - 1];
				}

				if (vet[j] >= i)
				{
					if (vet[j] - i <= pd[i][j])
					{
						pd[i][j] = vet[j] - i;
						cnt[i][j] = 1;
					}
				}
				else if (j)
				{
					if (pd[i - vet[j]][j - 1] < pd[i][j])
					{
						pd[i][j] = pd[i - vet[j]][j - 1];
						cnt[i][j] = cnt[i - vet[j]][j - 1] + 1;
					}
					else if (pd[i - vet[j]][j - 1] == pd[i][j])
					{
						cnt[i][j] = min(cnt[i][j], cnt[i - vet[j]][j - 1] + 1);
					}
				}
			}

		printf("%d %d\n", s + pd[s][n - 1], cnt[s][n - 1]);
	}
}