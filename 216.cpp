#include "pch.h"

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>

using namespace std;

#define ii pair<int, int>
#define inf 1000000

int PC;
int MMask;
double dist[10][10];
double pd[10][256];
bool check[10][256];


double tsp(int at, int mask)
{
	if (mask == MMask) return 0;
	if (check[at][mask]) return pd[at][mask];

	double resp = inf;
	for (int i = 0; i < PC; i++)
		if (at != i && (mask & (1 << i)) == 0)
			resp = min(resp, dist[at][i] + tsp(i, mask | (1 << i)));

	check[at][mask] = 1;
	return pd[at][mask] = resp;
}

vector<ii> POINTS;

void tsp_rec(int at, int mask)
{
	if (mask == MMask) return;

	double resp = inf;
	int besti;
	for (int i = 0; i < PC; i++)
		if (at != i && (mask & (1 << i)) == 0)
			if (dist[at][i] + tsp(i, (mask | (1 << i))) < resp)
			{
				resp = dist[at][i] + tsp(i, (mask | (1 << i)));
				besti = i;
			}

	ii a = POINTS[at];
	ii b = POINTS[besti];
	printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", a.first, a.second, b.first, b.second, dist[at][besti]);

	tsp_rec(besti, (mask | (1 << besti)));

	return;
}


int main()
{
	freopen("Input.txt", "r", stdin);

	int k = 1;
	while (scanf("%d", &PC) && PC)
	{
		MMask = (1 << PC) - 1;

		POINTS.clear();

		for (int i = 0; i < PC; i++)
		{
			int x, y; scanf("%d %d", &x, &y);
			POINTS.push_back(ii(x, y));
		}

		for (int i = 0; i < PC; i++)
			for (int j = i; j < PC; j++)
			{
				int a = abs(POINTS[i].first - POINTS[j].first);
				int b = abs(POINTS[i].second - POINTS[j].second);
				double c = sqrt(a * a + b * b);

				dist[i][j] = dist[j][i] = 16 + c;
			}

		double resp = inf;
		int besti;
		for (int i = 0; i < PC; i++)
		{
			memset(check, 0, sizeof(check));
			if (tsp(i, (1 << i)) < resp)
			{
				resp = tsp(i, (1 << i));
				besti = i;
			}
		}
		printf("**********************************************************\n");
		printf("Network #%d\n", k++);

		memset(check, 0, sizeof(check));
		tsp(besti, (1 << besti));

		tsp_rec(besti, (1 << besti));
		printf("Number of feet of cable required is %.2lf.\n", resp);
	}
}