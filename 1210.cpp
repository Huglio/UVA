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

bitset<10010> bs;

vector<int> primes;
int resp[10010];

void sieve()
{
	bs.set();

	for (ll i = 2; i <= 10000; i++)
	{
		if (bs[i])
		{
			primes.push_back((int)i);

			for (ll j = i * i; j <= 10000; j += i)
				bs[j] = 0;
		}
	}
}

int main()
{
	sieve();
	memset(resp, 0, sizeof(resp));

	for (int i = 0; i < (int)primes.size(); i++)
	{
		int sum = primes[i];
		resp[sum]++;

		for (int j = i - 1; j >= 0 && sum + primes[j] <= 10000; j--)
		{
			sum += primes[j];
			resp[sum]++;
		}
	}

	int n;
	while (scanf("%d", &n) && n)
		printf("%d\n", resp[n]);
}