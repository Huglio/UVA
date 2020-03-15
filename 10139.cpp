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
#include <list>
#include <limits.h>

using namespace std;

#define sieveBOUND 1000010
#define inf 100000000
#define BOUNDS 1000000
#define ll long long int
#define ii pair<int, int>
#define MOD 1000000007

#define sum(a, b) (ll)(((ll)(a % MOD) + (ll)(b % MOD)) % MOD)
#define mult(a, b) (ll)(((ll)(a % MOD) * (ll)(b % MOD)) % MOD)
#define goldenratio ((double)(1 + sqrt(5)) / 2)
#define binet(a) (ll)round((((double)pow(goldenratio, a) - (double)pow(-goldenratio, -a)) / sqrt(5)))

#define valid(a, b) (a >= 0 && a < R && b >= 0 && b < C && row[a] && column[b])

bitset<sieveBOUND> bs;
vector<int> primes;

void sieve()
{
	bs.set();

	for (ll i = 2; i < sieveBOUND; i++)
	{
		if (bs[i])
		{
			primes.push_back(i);
			for (ll j = i * i; j < sieveBOUND; j += i)
				bs[j] = 0;
		}
	}
}

int main()
{
	freopen("Input.txt", "r", stdin);

	sieve();

	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		bool divides = true;

		int aux = m;
		for (int i = 0; i < (int)primes.size() && (ll)primes[i] * primes[i] <= aux && divides; i++)
		{
			int cnt = 0;
			while (aux % primes[i] == 0) { cnt++; aux /= primes[i]; }

			int maxprimes = 0;
			for (int j = 1; maxprimes < cnt && pow(primes[i], j) <= n; j++)
				maxprimes += (n / pow(primes[i], j));

			if (maxprimes < cnt)
				divides = false;
		}

		if (aux != 1 && aux > n)
			divides = false;

		if (divides)
			printf("%d divides %d!\n", m, n);
		else
			printf("%d does not divide %d!\n", m, n);
	}
}