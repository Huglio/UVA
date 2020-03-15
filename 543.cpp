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

vector<int> primes;
bitset<1000010> bs;

void sieve()
{
	bs.set();

	for (ll i = 2; i < 1000000; i++)
	{
		if (bs[i])
		{
			primes.push_back(i);
			for (ll j = i * i; j < 1000000; j += i)
				bs[j] = 0;
		}
	}
}

int main()
{
	sieve();

	int n;
	while (scanf("%d", &n) && n)
	{
		int l = 0;
		int r = (int)primes.size() - 1;

		while (l != r)
		{
			int mid = (l + r) / 2;

			if (primes[mid] < n)
				l = mid + 1;
			else
				r = mid;
		}
		l = 0;

		while (l < r && primes[l] + primes[r] != n)
		{
			if (primes[l] + primes[r] > n)
				r--;
			if (primes[l] + primes[r] < n)
				l++;
		}

		if (primes[l] + primes[r] == n)
			printf("%d = %d + %d\n", n, primes[l], primes[r]);
		else
			printf("Goldbach's conjecture is wrong.\n");
	}
}