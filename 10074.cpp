#include "pch.h"

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define inf 1000000
#define ii pair<int, int>
#define ll long long int

int main()
{
	int n, m;
	
	while (scanf("%d %d", &n, &m) && (n || m))
	{
		int matrix[110][110];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &matrix[i][j]);

				if (i) matrix[i][j] += matrix[i - 1][j];
				if (j) matrix[i][j] += matrix[i][j - 1];
				if (i && j) matrix[i][j] -= matrix[i - 1][j - 1];
			}

		int resp = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				for (int r = i; r < n; r++)
					for (int s = j; s < m; s++)
					{
						int sum = matrix[r][s];
						if (i) sum -= matrix[i - 1][s];
						if (j) sum -= matrix[r][j - 1];
						if (i && j) sum += matrix[i - 1][j - 1];

						if (sum == 0)
							resp = max(resp, (r - i + 1) * (s - j + 1));
					}

		printf("%d\n", resp);
	}
}