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

bitset<100010> bs;
vector<int> primes;

void sieve()
{
	bs.set();

	for (ll i = 2; i < 100000; i++)
	{
		if (bs[i])
		{
			primes.push_back(i);

			for (ll j = i * i; j < 100000; j += i)
				bs[j] = 0;
		}
	}
}

int main()
{
	freopen("Input.txt", "r", stdin);

	sieve();

	int n;
	while (scanf("%d", &n) && n)
	{
		int aux = n;

		double result = aux;
		for (int i = 0; i < (int)primes.size() && (ll)primes[i] * primes[i] <= aux; i++)
		{
			if (aux % primes[i] == 0)
			{
				while (aux % primes[i] == 0)
					aux /= primes[i];

				result *= (1.00 - (1.00 / double(primes[i])));
			}
		}

		if (aux > 1)
			result *= (1.00 - (1.00 / double(aux)));

		printf("%d\n", (int)result);
	}
}