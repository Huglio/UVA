#include "pch.h"
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

#define ii pair<int, int>
#define inf 99999999

int n;
int business[210];
long long int dist[210];
int vis[210];

vector<int> adjlist[210];
void dfs(int at)
{
	//printf("visited: %d\n", at);
	vis[at] = 1;

	for (int to : adjlist[at])
		if (!vis[to])
			dfs(to);
}

int main()
{
	//freopen("Out.txt", "w", stdout);

	int t = 1;
	while (scanf(" %d", &n) != EOF)
	{
		for (int i = 0; i <= n; i++)
		{
			vis[i] = 0;
			dist[i] = inf;
			adjlist[i].clear();
		}

		for (int i = 1; i <= n; i++)
			scanf("%d", &business[i]);

		int r; scanf("%d", &r);

		vector<pair<long long int, ii> > edges;
		for (int i = 0; i < r; i++)
		{
			int x, y; scanf("%d %d", &x, &y);
		
			long long int z = business[y] - business[x];
			z = z * z * z;

			edges.push_back(pair<long long int, ii>(z, ii(x, y)));
			adjlist[x].push_back(y);
		}

		dist[1] = 0;
		for (int i = 0; i < n - 1; i++)
			for (pair<long long int, ii> v : edges)
				if (dist[v.second.first] + v.first < dist[v.second.second])
					dist[v.second.second] = dist[v.second.first] + v.first;

		for (int i = 0; i < n - 1; i++)
			for (pair<long long int, ii> v : edges)
				if (dist[v.second.first] + v.first < dist[v.second.second])
					dist[v.second.second] = -inf;

		dfs(1);

		/*for (int i = 1; i <= n; i++)
			printf(" %d", dist[i]);
*/
		int q; scanf("%d", &q);

		printf("Set #%d\n", t++);
		for (int i = 0; i < q; i++)
		{
			int query; scanf("%d", &query);

			if (dist[query] < 3 || !vis[query])
				printf("?\n");
			else
				printf("%d\n", dist[query]);
		}
	}
}