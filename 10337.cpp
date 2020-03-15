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

int main()
{
	int TC; scanf("%d", &TC);

	while (TC--)
	{
		int n; scanf("%d", &n); n /= 100;

		int matrix[100][100]; //TODO AUMENTAR PARA 1010 1010
		for (int i = 9; i >= 0; i--)
			for (int j = 0; j < n; j++)
				scanf("%d", &matrix[i][j]);

		for (int i = 1; i < 10; i++)
			matrix[i][0] = inf;

		for (int i = 9; i >= 0; i--)
		{
			for (int j = 0; j < n; j++)
				printf("%3d ", matrix[i][j]);
			printf("\n");
		}

		matrix[0][0] = -matrix[0][0];
		for(int j = 1; j < n; j++)
			for (int i = 0; i < 10; i++)
			{
				int resp = matrix[i][j - 1] + 30 - matrix[i][j];
				if (i) resp = min(resp, matrix[i - 1][j - 1] - matrix[i][j] + 60);
				if (i != 9) resp = min(resp, matrix[i + 1][j - 1] - matrix[i][j] + 20);

				matrix[i][j] = resp;
			}

		printf("\n");
		for (int i = 9; i >= 0; i--)
		{
			for (int j = 0; j < n; j++)
				printf("%3d ", matrix[i][j]);
			printf("\n");
		}

		int resp = min(matrix[0][n - 1] + 30, matrix[1][n - 1] + 20);

		printf("%d\n", resp);
	}
}