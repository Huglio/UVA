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
	bitset<32> A;
	bitset<32> B;

	bitset<32> x;

	int n;
	while (scanf("%d", &n) && n)
	{
		A.reset();
		B.reset();

		x = n;
		bool first = true;
		for (int i = 0; i < 32; i++)
		{
			if (x[i])
			{
				if (first)
					A[i] = 1;
				else
					B[i] = 1;

				first = !first;
			}
		}

		printf("%d %d\n", (int)A.to_ulong(), (int)B.to_ulong());
	}
}