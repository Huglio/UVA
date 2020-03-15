#include "pch.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
	int T; scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		int matrix[110][110];

		int n, m, k; scanf("%d %d %d", &n, &m, &k);

		for(int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &matrix[i][j]);

				if (i) matrix[i][j] = matrix[i][j] + matrix[i - 1][j];
				if (j) matrix[i][j] = matrix[i][j] + matrix[i][j - 1];
				if (i && j) matrix[i][j] = matrix[i][j] - matrix[i - 1][j - 1];
			}

		int besttam = 0;
		int bestprice = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				for (int r = i; r < n; r++)
					for (int s = j; s < m; s++)
					{
						int sum = matrix[r][s];

						if (i) sum = sum - matrix[i - 1][s];
						if (j) sum = sum - matrix[r][j - 1];
						if (i && j) sum = sum + matrix[i - 1][j - 1];

						if (sum <= k)
						{
							int tam = (r - i + 1) * (s - j + 1);

							if (tam > besttam)
							{
								besttam = tam;
								bestprice = sum;
							}
							else if (tam == besttam)
								bestprice = min(bestprice, sum);
						}
					}
		printf("Case #%d: %d %d\n", tc, besttam, bestprice);
	}
}