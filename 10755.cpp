#include "pch.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define inf 10000000

int main()
{
	int TC; scanf("%d", &TC);

	while (TC--)
	{
		int matrix[30][30][30];

		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		int resp = 0;

		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++)
				for (int k = 0; k < c; k++)
				{
					scanf("%d", &matrix[i][j][k]);
					resp += matrix[i][j][k];
				}

		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++)
				for (int r = i; r < a; r++)
					for (int s = j; s < b; s++)
					{
						int sum = 0;
						for (int n = 0; n < c; n++)
						{
							int value = 0;
							for (int g = i; g <= r; g++)
								for (int h = j; h <= s; h++)
									value += matrix[g][h][n];

							sum += value;
							resp = max(resp, sum);

							if (sum < 0)
								sum = 0;
						}
					}

		for (int i = 0; i < a; i++) //a
			for (int j = 0; j < c; j++) //c
				for (int r = i; r < a; r++)
					for (int s = j; s < c; s++)
					{
						long long int sum = 0;
						for (int n = 0; n < b; n++)
						{
							long long int value = 0;
							for (int g = i; g <= r; g++)
								for (int h = j; h <= s; h++)
									value += matrix[g][n][h];
							sum += value;
							resp = max(resp, sum);

							if (sum < 0)
								sum = 0;
						}
					}

		for (int i = 0; i < c; i++) //c
			for (int j = 0; j < b; j++) //b
				for (int r = i; r < c; r++)
					for (int s = j; s < b; s++)
					{
						long long int sum = 0;
						for (int n = 0; n < a; n++)
						{
							long long int value = 0;
							for (int g = i; g <= r; g++)
								for (int h = j; h <= s; h++)
									value += matrix[n][h][g];
							sum += value;
							resp = max(resp, sum);

							if (sum < 0)
								sum = 0;
						}
					}

		printf("%d\n", resp);

		if (TC)
			printf("\n");
	}
}