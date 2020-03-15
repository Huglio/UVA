#include "pch.h"

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <list>
#include <limits.h>

using namespace std;

#define sieveBOUND 1000010
#define inf 100000000
#define BOUNDS 1000000
#define ll long long int
#define ii pair<int, int>
#define MOD 10

#define sum(a, b) (ll)(((ll)(a % MOD) + (ll)(b % MOD)) % MOD)
#define mult(a, b) (((ll)(a % MOD) * (ll)(b % MOD)) % MOD)
#define goldenratio ((double)(1 + sqrt(5)) / 2)
#define binet(a) (ll)round((((double)pow(goldenratio, a) - (double)pow(-goldenratio, -a)) / sqrt(5)))

#define valid(a, b) (a >= 0 && a < R && b >= 0 && b < C && row[a] && column[b])

int main()
{
	freopen("Input.txt", "r", stdin);

	int n; scanf("%d", &n);

	vector<int> v(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	int q; scanf("%d", &q);

	for (int i = 0; i < q; i++)
	{
		int x; scanf("%d", &x);
		ii resp = ii(-1, -1);

		if (x < v[0])
			resp = ii(-1, v[0]);
		else if (x > v[n - 1])
			resp = ii(v[n - 1], -1);
		else
		{
			int l = 0;
			int r = n - 1;

			while (l != r)
			{
				int mid = (l + r) / 2;

				if (v[mid] <= x)
					l = mid + 1;
				else
					r = mid;
			}

			if(v[l] != x)
				resp.second = v[l];

			l = 0;
			r = n - 1;

			while (l != r)
			{
				int mid = (l + r) / 2;

				if (v[mid] >= x)
					r = mid;
				else
					l = mid + 1;
			}

			if (l - 1 >= 0 && v[l - 1] != x)
				resp.first = v[l - 1];
		}

		if (resp.first != -1)
			printf("%d", resp.first);
		else
			printf("X");

		if (resp.second != -1)
			printf(" %d", resp.second);
		else
			printf(" X");

		printf("\n");
	}
}