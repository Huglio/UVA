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
#define inf 1000000000
#define BOUNDS 1000000
#define ll long long int
#define ii pair<int, int>
#define db double
//#define MOD 10

#define sum(a, b) (ll)(((ll)(a % MOD) + (ll)(b % MOD)) % MOD)
#define mult(a, b) (((ll)(a % MOD) * (ll)(b % MOD)) % MOD)
#define goldenratio ((double)(1 + sqrt(5)) / 2)
#define binet(a) (ll)round((((double)pow(goldenratio, a) - (double)pow(-goldenratio, -a)) / sqrt(5)))

#define valid(a, b) (a >= 0 && a < R && b >= 0 && b < C && row[a] && column[b])

ll pd[25][150][150];

ll f(int index, int sum, int x)
{
	if (index <= 0) return sum >= x;
	if (pd[index][sum][x] != -1) return pd[index][sum][x];

	ll resp = 0;
	for (int i = 1; i <= 6; i++)
		resp += f(index - 1, sum + i, x);

	return pd[index][sum][x] = resp;
}

ll gcd(ll a, ll b)
{
	if (b == 0) return a;

	return gcd(b, a % b);
}

int main()
{
	memset(pd, -1, sizeof(pd));

	int n, x;
	while (scanf("%d %d", &n, &x) && (n || x))
	{
		ll num = f(n, 0, x);
		ll den = pow(6, n);

		ll div = gcd(num, den);
		num /= div;
		den /= div;

		printf("%lld", num);
		if (den != 1)
			printf("/%lld", den);
		printf("\n");
	}
}