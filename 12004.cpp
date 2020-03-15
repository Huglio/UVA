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
	freopen("Input.txt", "r", stdin);

	int TC; scanf("%d", &TC);

	for (int k = 1; k <= TC; k++)
	{
		ll n; scanf("%lld", &n);

		ll num = n * (n - 1);
		ll den = 4;

		while (num % 2 == 0 && den % 2 == 0)
		{
			num /= 2;
			den /= 2;
		}

		if (den == 1)
			printf("Case %d: %lld\n", k, num);
		else
			printf("Case %d: %lld/%lld\n", k, num, den);
	}
}