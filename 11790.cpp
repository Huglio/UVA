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
	int TC; scanf("%d", &TC);

	for (int t = 1; t <= TC; t++)
	{
		int n; scanf("%d", &n);

		vector<int> Input;
		vector<int> Length;

		for (int i = 0; i < n; i++)
		{
			int x; scanf("%d", &x);
			Input.push_back(x);
		}
		for (int i = 0; i < n; i++)
		{
			int x; scanf("%d", &x);
			Length.push_back(x);
		}

		vector<int> LLS(n);

		for (int i = 0; i < n; i++)
		{
			LLS[i] = Length[i];
			for (int j = i - 1; j >= 0; j--)
			{
				if (Input[j] < Input[i])
				{
					if (LLS[j] + Length[i] > LLS[i])
					{
						LLS[i] = LLS[j] + Length[i];
					}
				}
			}
		}

		int increasing = 0;
		for (int i = 0; i < n; i++)
			increasing = max(increasing, LLS[i]);

		for (int i = 0; i < n; i++)
		{
			LLS[i] = Length[i];
			for (int j = i - 1; j >= 0; j--)
			{
				if (Input[j] > Input[i])
				{
					if (LLS[j] + Length[i] > LLS[i])
					{
						LLS[i] = LLS[j] + Length[i];
					}
				}
			}
		}

		int decreasing = 0;
		for (int i = 0; i < n; i++)
			decreasing = max(decreasing, LLS[i]);

		if (increasing >= decreasing)
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", t, increasing, decreasing);
		else
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", t, decreasing, increasing);
	}
}