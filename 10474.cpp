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

	int n, q; int TC = 1;
	while (scanf("%d %d", &n, &q) && (n || q))
	{
		vector<int> v(n);

		for (int i = 0; i < n; i++)
			scanf("%d", &v[i]);

		sort(v.begin(), v.end());

		printf("CASE# %d:\n", TC++);
		while (q--)
		{
			int x; scanf("%d", &x);

			int l = 0;
			int r = n - 1;

			while (l != r)
			{
				int mid = (l + r) / 2;

				if (v[mid] < x)
					l = mid + 1;
				else
					r = mid;
			}

			if (v[l] == x)
				printf("%d found at %d\n", x, l + 1);
			else
				printf("%d not found\n", x);
		}
	}
}