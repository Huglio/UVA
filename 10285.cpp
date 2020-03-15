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
#define isValid(a, b) a >= 0 && a < n && b >= 0 && b < m

int n, m;

int pd[110][110];
int matrix[110][110];

int di[4] = { 0, 0, 1,-1 };
int dj[4] = { 1,-1, 0, 0 };

int f(int i, int j)
{
	if (pd[i][j] != -1) return pd[i][j];

	vector<ii> adjlist;
	for (int k = 0; k < 4; k++)
		if(isValid(i + di[k], j + dj[k]) && matrix[i + di[k]][j + dj[k]] < matrix[i][j])
			adjlist.push_back(ii(i + di[k], j + dj[k]));

	int resp = 0;
	for (ii u : adjlist)
		resp = max(resp, f(u.first, u.second));

	return pd[i][j] = resp + 1;
}

int main()
{
	freopen("Input.txt", "r", stdin);

	int t; cin >> t;

	while (t--)
	{
		string name; cin >> name >> n >> m;

		for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) pd[i][j] = -1;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &matrix[i][j]);

		int resp = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				resp = max(resp, f(i, j));

		cout << name << ": " << resp << endl;
	}
}