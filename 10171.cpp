#include "pch.h"
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

#define inf 999999
#define ii pair<int, int>

int dist_old[30][30];
int dist_young[30][30];

int main()
{
	freopen("Input.txt", "r", stdin);

	int n;
	while (scanf(" %d", &n) && n)
	{
		for (int i = 0; i < 30; i++) for (int j = 0; j < 30; j++) i == j ? dist_old[i][j] = 0 : dist_old[i][j] = inf;
		for (int i = 0; i < 30; i++) for (int j = 0; j < 30; j++) i == j ? dist_young[i][j] = 0 : dist_young[i][j] = inf;

		for (int i = 0; i < n; i++)
		{
			int x;
			char a, b, c, d; scanf(" %c %c %c %c %d", &a, &b, &c, &d, &x);

			if (a == 'M')
			{
				dist_old[c - 'A'][d - 'A'] = x;
				if (b == 'B')
					dist_old[d - 'A'][c - 'A'] = x;
			}
			else
			{
				dist_young[c - 'A'][d - 'A'] = x;
				if (b == 'B')
					dist_young[d - 'A'][c - 'A'] = x;
			}
		}

		for (int k = 0; k < 30; k++)
			for (int i = 0; i < 30; i++)
				for (int j = 0; j < 30; j++)
					if (dist_old[i][j] > dist_old[i][k] + dist_old[k][j])
						dist_old[i][j] = dist_old[i][k] + dist_old[k][j];

		for (int k = 0; k < 30; k++)
			for (int i = 0; i < 30; i++)
				for (int j = 0; j < 30; j++)
					if (dist_young[i][j] > dist_young[i][k] + dist_young[k][j])
						dist_young[i][j] = dist_young[i][k] + dist_young[k][j];

		char x, y; 
		scanf(" %c %c", &x, &y);

		x -= 'A';
		y -= 'A';

		int resp = inf;
		set<char> cities;

		if (x != y)
		{
			for (int i = 0; i < 30; i++)
			{
				int time = dist_young[x][i] + dist_old[y][i];

				if (time < resp)
					resp = time;
			}
		}
		else
		{
			resp = 0;
			cities.insert('A' + x);
		}

		if (resp == inf)
			printf("You will never meet.\n");
		else
		{
			for (int i = 0; i < 30; i++)
			{
				if (dist_young[x][i] + dist_old[y][i] == resp)
					cities.insert('A' + i);
			}

			printf("%d", resp);

			for (set<char>::iterator it = cities.begin(); it != cities.end(); it++)
				printf(" %c", *it);
			printf("\n");
		}
	}
}