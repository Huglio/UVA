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
#define inf 1000000010
#define BOUNDS 1000000
#define ll long long int
#define ii pair<int, int>
#define db double
//#define MOD 10

#define sum(a, b) (ll)(((ll)(a % MOD) + (ll)(b % MOD)) % MOD)
#define mult(a, b) (((ll)(a % MOD) * (ll)(b % MOD)) % MOD)
#define goldenratio ((double)(1 + sqrt(5)) / 2)
#define binet(a) (ll)round((((double)pow(goldenratio, a) - (double)pow(-goldenratio, -a)) / sqrt(5)))
#define eulerconstant 0.577215664901532

ll power(ll a, ll e, ll MOD)
{
	ll resp = 1;
	while (e)
	{
		if (e % 2)
			resp = mult(resp, a);
		a = mult(a, a);
		e /= 2;
	}

	return resp;
}

int main()
{
	int TC; scanf("%d", &TC);

	while (TC--)
	{
		ll x, y, n; scanf("%lld %lld %lld", &x, &y, &n);

		printf("%lld\n", power(x, y, n));
	}
}