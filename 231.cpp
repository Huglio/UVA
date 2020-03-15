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

	int TC = 1;
	int x;
	while (scanf("%d", &x) && x != -1)
	{
		if (TC != 1)
			printf("\n");

		vector<int> Input;
		Input.push_back(x);

		while (scanf("%d", &x) && x != -1)
			Input.push_back(x);

		vector<int> V;
		for (int i = 0; i < (int)Input.size(); i++)
		{
			if (V.empty() || V.back() > Input[i])
				V.push_back(Input[i]);
			else
			{
				int l = 0;
				int r = V.size() - 1;

				while (l != r)
				{
					int mid = (l + r) / 2;

					if (V[mid] < Input[i])
						r = mid;
					else
						l = mid + 1;
				}

				V[l] = Input[i];
			}
		}

		printf("Test #%d:\n", TC++);
		printf("  maximum possible interceptions: %d\n", (int)V.size());
	}
}