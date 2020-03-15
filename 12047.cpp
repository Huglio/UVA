#include "pch.h"
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

#define ii pair<int, int>

vector<int> adjlist[10010];
vector<int> transposta[10010];
vector<ii> edges;
int weight[10010][10010];
int dist_t[10010];
int dist[10010];

int main()
{
	freopen("Input.txt", "r", stdin);

	int test; scanf("%d", &test);

	while (test--)
	{
		int n, m, s, t, p; scanf("%d %d %d %d %d", &n, &m, &s, &t, &p);

		for (int i = 0; i <= n; i++) adjlist[i].clear();
		for (int i = 0; i <= n; i++) transposta[i].clear();
		edges.clear();

		for (int i = 0; i < m; i++)
		{
			int u, v, c; scanf("%d %d %d", &u, &v, &c);

			weight[u][v] = c;

			adjlist[u].push_back(v);
			transposta[v].push_back(u);

			edges.push_back(ii(u, v));
		}

		memset(dist, -1, sizeof dist);
		memset(dist_t, -1, sizeof dist_t);

		priority_queue<ii, vector<ii>, greater<ii> > q;

		q.push(ii(0, s));
		dist[s] = 0;

		while (!q.empty())
		{
			int r = q.top().second; q.pop();

			for (int u : adjlist[r])
			{
				if (dist[u] == -1 || dist[u] > dist[r] + weight[r][u])
				{
					dist[u] = dist[r] + weight[r][u];
					q.push(ii(dist[u], u));
				}
			}
		}

		q.push(ii(0, t));
		dist_t[t] = 0;

		while (!q.empty())
		{
			int r = q.top().second; q.pop();

			for (int u : transposta[r])
			{
				//printf("%d\n", weight[u][r]);

				if (dist_t[u] == -1 || dist_t[u] > dist_t[r] + weight[u][r])
				{ 
					//printf("a %d\n", dist_t[u]);
					dist_t[u] = dist_t[r] + weight[u][r];
					//printf("d %d\n", dist_t[u]);
					q.push(ii(dist_t[u], u));
				}
			}
		}

		/*for (int i = 1; i <= n; i++)
			printf("%d ", dist_t[i]);
		printf("\n");*/

		int resp = -1;

		for (int i = 0; i < (int)edges.size(); i++)
		{
			int r = edges[i].first;
			int u = edges[i].second;

			
			if (dist[r] != -1 && dist_t[u] != -1 && dist[r] + dist_t[u] + weight[r][u] <= p)
			{
				//printf("%d to %d : %d\ndist[%d]: %d to dist_t[%d]: %d\n", r, u, weight[r][u], r, dist[r], u, dist_t[u]);
				resp = max(resp, weight[r][u]);
			}
		}

		printf("%d\n", resp);
	}
}