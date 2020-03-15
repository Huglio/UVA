#include "pch.h"
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <cmath>

using namespace std;

#define ii pair<int, int>

bool reach[5][110];
vector<int> floors[5];
int cost[5];

int bfs(int n, int k)
{
	int dist[5][110];
	memset(dist, -1, sizeof dist);

	priority_queue<pair<int, ii>, vector<pair<int, ii> >, greater<pair<int, ii> > > q;

	dist[0][0] = dist[1][0] = dist[2][0] = dist[3][0] = dist[4][0] = 0;

	for (int i = 0; i < n; i++)
		if (floors[i][0] == 0)
			q.push(pair<int, ii>(0, ii(0, i)));

	while (!q.empty())
	{
		pair<int, ii> r = q.top(); q.pop();

		//Switch elevators
		for (int i = 0; i < n; i++)
		{
			if (i == r.second.second) continue;

			if (reach[i][r.second.first] && (dist[i][r.second.first] == -1 || dist[i][r.second.first] > r.first + 60))
			{
				dist[i][r.second.first] = r.first + 60;
				q.push(pair<int, ii>(r.first + 60, ii(r.second.first, i)));

				//cout << r.second.first << ": On elevator: " << r.second.second << " going to " << i << " dist: " << dist[i][r.second.first] << endl;
				//getchar();
			}
		}

		//Switch floors
		int elev = r.second.second;
		for (int i = 0; i < (int)floors[elev].size(); i++)
		{
			if (dist[elev][floors[elev][i]] == -1 || dist[elev][floors[elev][i]] > r.first + cost[elev] * abs(floors[elev][i] - r.second.first))
			{
				//cout << (dist[elev][floors[elev][i]] == -1) << endl;
				//cout << r.first + cost[elev] * abs(floors[elev][i] - r.second.first) << endl;
				dist[elev][floors[elev][i]] = r.first + cost[elev] * abs(floors[elev][i] - r.second.first);
				q.push(pair<int, ii>(dist[elev][floors[elev][i]], ii(floors[elev][i], elev)));

				//cout << r.second.first << ": On elevator: " << elev << " to floor " << floors[elev][i] << " dist: " << dist[elev][floors[elev][i]] << endl;
				//getchar();
			}
		}
	}

	vector<int> resp;
	for (int i = 0; i < 5; i++)
		if (dist[i][k] != -1)
			resp.push_back(dist[i][k]);

	if (resp.size())
	{
		sort(resp.begin(), resp.end());
		return resp[0] != -1 ? resp[0] : resp[1] != -1 ? resp[1] : resp[2] != -1 ? resp[2] : resp[3] != -1 ? resp[3] : resp[4] != -1 ? resp[4] : -1;
	}
	else
		return -1;
}

int main()
{
	freopen("Input.txt", "r", stdin);

	int n, k;
	while (cin >> n >> k)
	{
		memset(reach, 0, sizeof reach);
		for (int i = 0; i < n; i++)
			floors[i].clear();

		for (int i = 0; i < n; i++)
			cin >> cost[i];

		cin.ignore();
		for (int i = 0; i < n; i++)
		{
			string str; getline(cin, str);
			stringstream ss(str);
			string num;

			while (ss >> num)
			{
				int floor = stoi(num);

				floors[i].push_back(floor);
				reach[i][floor] = 1;
			}
		}

		/*for (int i = 0; i < n; i++)
		{
			cout << "Elevador " << i << " : ";
			for (int j = 0; j < (int)floors[i].size(); j++)
				cout << " " << floors[i][j];
			cout << endl;
		}*/

		int resp = bfs(n, k);

		if (resp != -1)
			cout << resp << endl;
		else
			cout << "IMPOSSIBLE" << endl;
	}
}