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
	freopen("Input.txt", "r", stdin);

	int TC; scanf("%d", &TC);

	while (TC--)
	{
		int n; scanf("%d", &n);

		vector<int> Input;
		for (int i = 0; i < n; i++)
		{
			int x; scanf("%d", &x);
			Input.push_back(x);
		}

		vector<int> V;
		for (int i = n - 1; i >= 0; i--)
			V.push_back(Input[i]);
		for (int i = 0; i < n; i++)
			V.push_back(Input[i]);
		n = 2 * n;

		vector<int> LIS(n);
		for (int i = 0; i < n; i++)
		{
			LIS[i] = 1;
			for (int j = i - 1; j >= 0; j--)
				if (V[j] < V[i])
					LIS[i] = max(LIS[i], LIS[j] + 1);
		}

		int resp = 0;
		for (int i = 0; i < n; i++)
			resp = max(resp, LIS[i]);

		printf("%d\n", resp);

	}
}