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

bitset<20> bs;
vector<int> primes;

void sieve()
{
	bs.set();

	for (int i = 2; i < 20; i++)
	{
		if (bs[i])
		{
			primes.push_back(i);

			for (int j = i * i; j < 20; j += i)
				bs[j] = 0;
		}
	}
}

ll power(int n, int e)
{
	if (e == 1) return n;
	if (e == 0) return 1;

	ll resp = power(n, e / 2);
	resp = resp * resp;

	if (e % 2) resp = resp * n;

	return resp;
}

int main()
{
	sieve();

	int TC; scanf("%d", &TC);

	for (int k = 1; k <= TC; k++)
	{
		vector<ll> cnt(primes.size(), 0);

		string str; cin >> str;
		int n = int(str.length());

		for (int i = 0; i < (int)primes.size() && primes[i] <= n; i++)
			for (int j = 1; power(primes[i], j) <= n; j++)
				cnt[i] += (n / power(primes[i], j));

		for (int i = 'A'; i <= 'Z'; i++)
		{
			int repeats = 0;
			for (int j = 0; j < n; j++)
				if (str[j] == i)
					repeats++;

			for (int j = 0; j < (int)primes.size() && primes[j] <= repeats; j++)
				for (int l = 1; power(primes[j], l) <= repeats; l++)
					cnt[j] -= (repeats / power(primes[j], l));
		}

		ll resp = 1;
		for (int i = 0; i < (int)cnt.size(); i++)
			resp = resp * power(primes[i], cnt[i]);

		printf("Data set %d: %lld\n", k, resp);
	}
}