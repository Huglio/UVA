#include "pch.h"
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define inf 99999999
#define ii pair<int, int>

int main()
{
	freopen("Input.txt", "r", stdin);

	int dist[110][110];
	int a, b;

	int t = 1;
	while (scanf("%d %d", &a, &b) && (a || b))
	{
		int n = max(a, b);
		vector<ii> input;

		input.push_back(ii(a, b));
		while (scanf("%d %d", &a, &b) && (a || b))
		{
			n = max(n, a);
			n = max(n, b);

			input.push_back(ii(a, b));
		}

		for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++)
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = inf;

		for (int i = 0; i < (int)input.size(); i++)
			dist[input[i].first][input[i].second] = 1;

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (dist[i][j] > dist[i][k] + dist[k][j])
						dist[i][j] = dist[i][k] + dist[k][j];

		/*for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				printf("%10d", dist[i][j]);
			printf("\n");
		}
		printf("\n");*/

		int cnt = 0;
		int clicks = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dist[i][j] != inf && i != j)
				{
					cnt += dist[i][j];
					clicks++;
				}

		double resp = (double)cnt/clicks;

		printf("Case %d: average length between pages = %.3lf clicks\n", t++, resp);
	}
}