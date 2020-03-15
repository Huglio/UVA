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

bitset<BOUNDS> bs;
vector<int> primes;

void sieve()
{
	bs.set();
	bs[0] = bs[1] = 0;

	for (ll i = 2; i < BOUNDS; i++)
	{
		if (bs[i])
		{
			primes.push_back(i);

			for (ll j = i * i; j < BOUNDS; j += i)
				bs[j] = 0;
		}
	}
}

bool isprime(int n)
{
	if (n < BOUNDS)
		return bs[n];

	int i;
	for (int p : primes)
	{
		if (n % p == 0)
			return false;
		if ((ll)p * p > n)
			return true;
	}

	return true;
}

int main()
{
	sieve();

	int L, U;
	while (scanf("%d %d", &L, &U) != EOF)
	{
		ii close, far;
		int closedistance = -1;
		int fardistance = -1;
		int lastprime = -1;
		for (int i = L; i <= U; i++)
		{
			if (isprime(i))
			{
				if (lastprime != -1)
				{
					if (closedistance == -1 || i - lastprime < closedistance)
					{
						close.second = i;
						close.first = lastprime;
						closedistance = i - lastprime;
					}
					if (fardistance == -1 || i - lastprime > fardistance)
					{
						far.second = i;
						far.first = lastprime;
						fardistance = i - lastprime;
					}
				}
				lastprime = i;
			}
		}

		if (closedistance != -1 && fardistance != -1)
			printf("%d,%d are closest, %d,%d are most distant.\n", close.first, close.second, far.first, far.second);
		else
			printf("There are no adjacent primes.\n");
	}
}