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
#include <queue>
#include <string>
#include <set>
#include <cmath>
#include <stack>
#include <limits.h>

using namespace std;

#define inf 100000000
#define BOUNDS 1000000
#define ll long long int
#define ii pair<int, int>
#define MOD 1000000007

#define sum(a, b) (ll)(((ll)(a % MOD) + (ll)(b % MOD)) % MOD)
#define mult(a, b) (ll)(((ll)(a % MOD) * (ll)(b % MOD)) % MOD)

#define valid(a, b) (a >= 0 && a < R && b >= 0 && b < C && row[a] && column[b])

int main()
{
	bitset<1000010> bs;

	int n, m;
	while (scanf("%d %d", &n, &m) && (n || m))
	{
		bs.reset();
		bool ok = true;

		while (n--)
		{
			int x, y; scanf("%d %d", &x, &y);

			for (int i = x; i < y && ok; i++)
			{
				if (bs[i])
					ok = false;
				else
					bs[i] = 1;
			}
		}

		while (m--)
		{
			int x, y, z; scanf("%d %d %d", &x, &y, &z);

			while (x < 1000000)
			{
				for (int i = x; i < y && ok; i++)
				{
					if (bs[i])
						ok = false;
					else
						bs[i] = 1;
				}

				x += z;
				y += z;
			}
		}

		if (ok)
			printf("NO CONFLICT\n");
		else
			printf("CONFLICT\n");
	}
}