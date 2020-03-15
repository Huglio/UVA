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
	freopen("Input.txt", "r", stdin);

	int TC; scanf("%d", &TC);
	cin.ignore();
	while (TC--)
	{
		cin.ignore();
		int matrix[30][30];

		string str; getline(cin, str);
		int n = str.length();

		for (int i = 0; i < n; i++)
			matrix[0][i] = str[i] - '0';

		for (int i = 1; i < n; i++)
		{
			getline(cin, str);
			for (int j = 0; j < n; j++)
				matrix[i][j] = str[j] - '0';
		}

		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (i) matrix[i][j] += matrix[i - 1][j];
				if (j) matrix[i][j] += matrix[i][j - 1];
				if (i && j) matrix[i][j] -= matrix[i - 1][j - 1];
			}

		int resp = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int r = i; r < n; r++)
					for (int s = j; s < n; s++)
					{
						int sum = matrix[r][s];
						if (i) sum -= matrix[i - 1][s];
						if (j) sum -= matrix[r][j - 1];
						if (i && j) sum += matrix[i - 1][j - 1];

						if (sum == (r - i + 1) * (s - j + 1))
							resp = max(resp, sum);
					}

		printf("%d\n", resp);
		if (TC)
			printf("\n");
	}
}