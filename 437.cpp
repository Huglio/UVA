#include "pch.h"

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;

#define inf 1000000
#define ii pair<int, int>
#define ll long long int

bool func(pair<ii, int> A, pair<ii, int> B)
{
	int Amax = A.first.second;
	int Amin = A.first.first;

	int Bmax = B.first.second;
	int Bmin = B.first.first;

	if (Amax == Bmax)
		return Amin > Bmin;
	return Amax > Bmax;
}

int main()
{
	int n;
	int TC = 1;
	while (scanf("%d", &n) && n)
	{
		vector<pair<ii, int> > Input;
		for (int i = 0; i < n; i++)
		{
			int x, y, z; scanf("%d %d %d", &x, &y, &z);
			Input.push_back(pair<ii, int>(ii(min(x, y), max(x, y)), z));
			Input.push_back(pair<ii, int>(ii(min(x, z), max(x, z)), y));
			Input.push_back(pair<ii, int>(ii(min(y, z), max(y, z)), x));
		}

		sort(Input.begin(), Input.end(), func);
		
		/*for (int i = 0; i < 3 * n; i++)
			printf("%d %d\n", Input[i].first.first, Input[i].first.second);
		printf("\n");*/

		vector<int> LIS(3 * n);
		for (int i = 0; i < 3 * n; i++)
		{
			LIS[i] = Input[i].second;
			for (int j = i - 1; j >= 0; j--)
				if (Input[i].first.first < Input[j].first.first && Input[i].first.second < Input[j].first.second)
					LIS[i] = max(LIS[i], LIS[j] + Input[i].second);
		}

		int resp = 0;
		for (int i = 0; i < 3 * n; i++)
			resp = max(resp, LIS[i]);
		
		printf("Case %d: maximum height = %d\n", TC++, resp);
	}
}