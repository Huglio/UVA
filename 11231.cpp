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
	int n, m, c;
	while (scanf("%d %d %d", &n, &m, &c) && (n || m || c))
	{
		n = n - 7;
		m = m - 7;

		
		ll resp = 0;
		if (c == 0)
		{
			resp += (m / 2) * ((n + 1) / 2);
			resp += ((m + 1) / 2) * (n / 2);
		}
		else
		{
			resp += ((m + 1) / 2) * ((n + 1) / 2);
			resp += (m / 2) * (n / 2);
		}

		printf("%lld\n", resp);
		
	}
}