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
//#define MOD 10

#define sum(a, b) (ll)(((ll)(a % MOD) + (ll)(b % MOD)) % MOD)
#define mult(a, b) (((ll)(a % MOD) * (ll)(b % MOD)) % MOD)
#define goldenratio ((double)(1 + sqrt(5)) / 2)
#define binet(a) (ll)round((((double)pow(goldenratio, a) - (double)pow(-goldenratio, -a)) / sqrt(5)))

#define valid(a, b) (a >= 0 && a < R && b >= 0 && b < C && row[a] && column[b])

ll MOD;

ll power(ll n, ll e)
{
	ll r = 1;
	while (e > 0)
	{
		if (e % 2) r = mult(r, n);
		n = mult(n, n);
		e /= 2;
	}
	return r;
}

int main()
{
	freopen("Input.txt", "r", stdin);

	ll TC; scanf("%lld", &TC);

	for (ll tc = 1; tc <= TC; tc++)
	{
		ll n, k; scanf("%lld %lld %lld", &n, &k, &MOD);

		ll resp = 0;
		for (int i = 0; i < n; i++)
		{
			ll x; scanf("%lld", &x);
			resp = sum(resp, x);
		}

		resp = mult(resp, mult(k, power(n, k - 1)));

		printf("Case %lld: %lld\n", tc, resp);
	}
}