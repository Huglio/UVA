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

	int n;
	while (scanf("%d", &n) != EOF)
	{
		vector<int> input(n);

		for (int i = 0; i < n; i++)
			scanf("%d", &input[i]);

		vector<int> V;
		int LISA[10010];
		int LISB[10010];

		for (int i = 0; i < n; i++)
		{
			if (V.empty() || V.back() < input[i])
			{
				V.push_back(input[i]);
				LISA[i] = V.size();
			}
			else
			{
				int l = 0;
				int r = V.size() - 1;

				while (l != r)
				{
					int mid = (l + r) / 2;

					if (V[mid] < input[i])
						l = mid + 1;
					else
						r = mid;
				}

				V[l] = input[i];
				LISA[i] = l + 1;
			}
		}


		V.clear();
		for (int i = n - 1; i >= 0; i--)
		{
			if (V.empty() || V.back() < input[i])
			{
				V.push_back(input[i]);
				LISB[i] = V.size();
			}
			else
			{
				int l = 0;
				int r = V.size() - 1;

				while (l != r)
				{
					int mid = (l + r) / 2;

					if (V[mid] < input[i])
						l = mid + 1;
					else
						r = mid;
				}

				V[l] = input[i];
				LISB[i] = l + 1;
			}
		}

		/*for (int i = 0; i < n; i++)
			printf("%d ", LISA[i]);
		printf("\n");
		for (int i = 0; i < n; i++)
			printf("%d ", LISB[i]);
		printf("\n");*/

		int resp = 1;

		for (int i = 0; i < n; i++)
				resp = max(resp, min(LISA[i] , LISB[i]) * 2 - 1);

		printf("%d\n", resp);
	}
}