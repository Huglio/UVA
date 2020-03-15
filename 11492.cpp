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

vector<string> languages[4010];
vector<int> adjlist[2010];
int weight[2010];
map<string, int> W;
map<string, int> T;

int main()
{
	int n;
	while (cin >> n && n)
	{
		for (int i = 0; i < 4010; i++) languages[i].clear();
		for (int i = 0; i < 2010; i++) adjlist[i].clear();

		W.clear();
		T.clear();
		int cnt = 0;
		string o, d; cin >> o >> d;

		T[o] = cnt++;
		T[d] = cnt++;

		while (n--)
		{
			string a, b, word; cin >> a >> b >> word;

			if (T.find(a) == T.end())
				T[a] = cnt++;
			if (T.find(b) == T.end())
				T[b] = cnt++;

			languages[T[a]].push_back(word);
			languages[T[b]].push_back(word);
		}

		int wcnt = 2;
		for(int i = 0; i < cnt; i++)
			for(int j = 0; j < (int)languages[i].size(); j++)
				for (int k = 0; k < (int)languages[i].size(); k++)
				{
					if (j == k) continue;

					string a = languages[i][j];
					string b = languages[i][k];

					if (W.find(a) == W.end())
					{
						weight[wcnt] = (int)a.length();
						W[a] = wcnt++;
					}
					if (W.find(b) == W.end())
					{
						weight[wcnt] = (int)b.length();
						W[b] = wcnt++;
					}

					if (a[0] != b[0])
					{
						adjlist[W[a]].push_back(W[b]);
						adjlist[W[b]].push_back(W[a]);
					}
				}

		weight[0] = weight[1] = 0;

		for (int i = 0; i < languages[0].size(); i++)
		{
			adjlist[0].push_back(W[languages[0][i]]);
			adjlist[W[languages[0][i]]].push_back(0);
		}
		for (int i = 0; i < languages[1].size(); i++)
		{
			adjlist[1].push_back(W[languages[1][i]]);
			adjlist[W[languages[1][i]]].push_back(1);
		}

		int dist[2010];
		memset(dist, -1, sizeof dist);

		priority_queue<ii, vector<ii>, greater<ii> > q;
		q.push(ii(0, 0));
		dist[0] = 0;

		while (!q.empty())
		{
			ii r = q.top(); q.pop();

			for (int u : adjlist[r.second])
			{
				if (dist[u] == -1 || dist[u] > r.first + weight[u])
				{
					q.push(ii(r.first + weight[u], u));
					dist[u] = r.first + weight[u];
				}
			}
		}

		if (dist[1] == -1)
			cout << "impossivel" << endl;
		else
			cout << dist[1] << endl;
	}
}