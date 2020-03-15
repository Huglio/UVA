#include "pch.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define inf 1000000
#define ll long long int

int main()
{
	int TC; scanf("%d", &TC);
	
	while (TC--)
	{
		int n, s; scanf("%d %d", &n, &s);
		int m = 0;

		int pd[310][310];

		int inputA[50];
		int inputB[50];

		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &inputA[m], &inputB[m]);

			if (inputA[m] <= 300 && inputB[m] <= 300)
				m++;
		}

		for (int i = 0; i <= 300; i++)
			for (int j = 0; j <= 300; j++)
				pd[i][j] = inf;

		pd[0][0] = 0;

		for (int i = 0; i <= 300; i++)
			for (int j = 0; j <= 300; j++)
				for (int k = 0; k < m; k++)
					if (inputA[k] <= i && inputB[k] <= j)
						pd[i][j] = min(pd[i][j], 1 + pd[i - inputA[k]][j - inputB[k]]);

		int resp = inf;

		for (int i = 0; i <= 300; i++)
			for (int j = 0; j <= 300; j++)
				if (pd[i][j] != inf)
				{
					int sq = (i * i) + (j * j);
					int root = round(sqrt(sq));

					if (root * root == sq && root == s)
						resp = min(resp, pd[i][j]);
				}

		if (resp == inf)
			printf("not possible\n");
		else
			printf("%d\n", resp);
	}
}