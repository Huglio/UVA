#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <string>
#include <cstring>
#include <set>

using namespace std;


int r, c, m, n;

#define valid(a, b) (a >= 0 && a < r && b >= 0 && b < c && !water[a][b])
#define ii pair<int, int>

bool vis[110][110];
bool water[110][110];

int odds = 0;
int evens = 0;

vector<int> di;
vector<int> dj;

void f(int x, int y)
{
	vis[x][y] = 1;

	set<ii> Check;
	for (int k = 0; k < 8; k++)
		if (valid(x + di[k], y + dj[k]))
			Check.insert(ii(x + di[k], y + dj[k]));

	for (int k = 0; k < 8; k++)
		if (valid(x + di[k], y + dj[k]) && !vis[x + di[k]][y + dj[k]])
				f(x + di[k], y + dj[k]);

	//printf("On: %d %d, %d ops\n", x, y, (int)Check.size());

	if ((int)Check.size() % 2)
		odds++;
	else
		evens++;
}

int main()
{
	freopen("Input.txt", "r", stdin);

	int t; scanf("%d", &t);

	for (int k = 1; k <= t; k++)
	{
		odds = 0;
		evens = 0;
		memset(vis, 0, sizeof vis);
		memset(water, 0, sizeof water);

		scanf("%d %d %d %d", &r, &c, &m, &n);

		di = { m, m,-m,-m, n, n,-n,-n };
		dj = { n,-n, n,-n, m,-m, m,-m };

		int w; scanf("%d", &w);

		for (int i = 0; i < w; i++)
		{
			int x, y; scanf("%d %d", &x, &y);
			water[x][y] = 1;
		}

		f(0, 0);

		printf("Case %d: %d %d\n", k, evens, odds);
	}
}