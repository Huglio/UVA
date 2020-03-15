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

bitset<1000010> bs;
bitset<1000010> mu;
int M[1000010];
int m[1000010];
int factors[1000010];

void sieve()
{
	bs.set();
	mu.set();

	for (ll i = 2; i < 1000000; i++)
	{
		if (bs[i])
		{
			factors[i] = 1;

			for (ll j = 2 * i; j < 1000000; j += i)
			{
				bs[j] = 0;
				factors[j]++;
			}

			for (ll j = i * i; j < 1000000; j += i * i)
				mu[j] = 0;
		}
	}
}

int main()
{
	sieve();

	M[1] = 1;
	m[1] = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		M[i] = M[i - 1];

		if (mu[i])
		{
			if (factors[i] % 2)
				m[i] = -1;
			else
				m[i] = 1;
		}

		M[i] += m[i];
	}

	int n;
	while (scanf("%d", &n) && n)
	{
		printf("%8d%8d%8d\n", n, m[n], M[n]);
	}
}