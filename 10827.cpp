#include "pch.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define inf 999999999

int main()
{
	freopen("Input.txt", "r", stdin);

	int TC; scanf("%d", &TC);

	while (TC--)
	{
		int Matrix[160][160];

		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &Matrix[i][j]);

		//1 quadrant
		for (int i = 0; i < n; i++)
			for (int j = n; j < n * 2; j++)
				Matrix[i][j] = Matrix[i][j - n];

		//3 quadrant
		for (int i = n; i < n * 2; i++)
			for (int j = 0; j < n; j++)
				Matrix[i][j] = Matrix[i - n][j];

		//4 quadrant
		for (int i = n; i < n * 2; i++)
			for (int j = n; j < n * 2; j++)
				Matrix[i][j] = Matrix[i - n][j - n];

		for (int i = 0; i < n * 2; i++)
			for (int j = 0; j < n * 2; j++)
			{
				if (i) Matrix[i][j] = Matrix[i][j] + Matrix[i - 1][j];
				if (j) Matrix[i][j] = Matrix[i][j] + Matrix[i][j - 1];
				if (i && j) Matrix[i][j] = Matrix[i][j] - Matrix[i - 1][j - 1];
			}

		int resp = -inf;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int r = i; r < n * 2 && r - i < n; r++)
					for (int s = j; s < n * 2 && s - j < n; s++)
					{
						int sum = Matrix[r][s];

						if (i) sum = sum - Matrix[i - 1][s];
						if (j) sum = sum - Matrix[r][j - 1];
						if (i && j) sum = sum + Matrix[i - 1][j - 1];

						resp = max(resp, sum);
					}

		printf("%d\n", resp);
	}
}