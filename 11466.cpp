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

using namespace std;

#define inf 1000000000
#define ll long long int
#define ii pair<ll, ll>
#define MOD 1000000007

#define sum(a, b) (ll)(((ll)(a % MOD) + (ll)(b % MOD)) % MOD)
#define mult(a, b) (ll)(((ll)(a % MOD) * (ll)(b % MOD)) % MOD)

vector<int> primes;
bitset<10000010> bs;

void sieve()
{
	bs.set();

	for (ll i = 2; i <= 10000000; i++)
	{
		if (bs[i])
		{
			primes.push_back(i);

			for (ll j = i * i; j <= 10000000; j += i)
				bs[j] = 0;
		}
	}
}

int main()
{
	freopen("Input.txt", "r", stdin);

	sieve();

	ll n;
	while (scanf("%lld", &n) && n)
	{
		int divs = 0;
		n = n < 0 ? n * -1 : n;

		ll MaxPrime = -1;
		for (int i = 0; i < (int)primes.size() && primes[i] * primes[i] <= n; i++)
		{
			if (n % primes[i] == 0)
				divs++;

			while (n % primes[i] == 0)
			{
				n /= primes[i];
				MaxPrime = max(MaxPrime, (ll)primes[i]);
			}
		}

		if (n != 1 && MaxPrime != n)
		{
			divs++;
			MaxPrime = max(MaxPrime, n);
		}

		if (divs > 1)
			printf("%lld\n", MaxPrime);
		else
			printf("-1\n");
	}
}