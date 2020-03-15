#include "pch.h"
#include <stdio.h>
#include <vector>

using namespace std;

#define inf 99999999

int n;
int dist[110];
bool vis[110];
vector<int> adjlist[110];

bool dfs(int node)
{
	vis[node] = 1;

	if (node == n && dist[node] > 0) return true;
	if (dist[node] <= 0) return false;

	bool ok = 0;
	for (int i = 0; i < (int)adjlist[node].size() && !ok; i++)
		if(!vis[adjlist[node][i]])
			ok = dfs(adjlist[node][i]);

	return ok;
}

int main()
{
	freopen("Input.txt", "r", stdin);

	while (scanf("%d", &n) && n != -1)
	{
		for (int i = 0; i <= n; i++) adjlist[i].clear();
		int energy[110];

		for (int i = 1; i <= n; i++)
		{
			int e, k; scanf("%d %d", &e, &k);
			energy[i] = e;

			for (int j = 0; j < k; j++)
			{
				int x; scanf("%d", &x);
				adjlist[i].push_back(x);
				//Caso dar merda, tenta comentar isso
				//adjlist[x].push_back(i);
			}
		}

		for (int i = 0; i <= n; i++) dist[i] = -inf;
		for (int i = 0; i <= n; i++) vis[i] = 0;

		dist[1] = 100;

		for (int i = 0; i < n - 1; i++)
			for (int j = 1; j <= n; j++)
				for (int v : adjlist[j])
					if (dist[j] + energy[v] > dist[v] && dist[j] + energy[v] > 0)
						dist[v] = dist[j] + energy[v];

		/*for (int i = 1; i <= n; i++)
			printf(" %d,", dist[i]);
		printf("\n");*/

		for (int i = 0; i < n - 1; i++)
			for (int j = 1; j <= n; j++)
				for (int v : adjlist[j])
					if (dist[j] + energy[v] > dist[v] && dist[j] + energy[v] > 0)
						dist[v] = inf;

		/*for (int i = 1; i <= n; i++)
			printf(" %d,", dist[i]);
		printf("\n");*/

		if (dfs(1))
			printf("winnable\n");
		else
			printf("hopeless\n");
	}
}