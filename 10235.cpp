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

bitset<1000010> bs;

vector<int> primes;

void sieve()
{
	bs.set();

	for (ll i = 2; i <= 1000000; i++)
	{
		if (bs[i])
		{
			primes.push_back((int)i);

			for (ll j = i * i; j <= 1000000; j += i)
				bs[j] = 0;
		}
	}
}

bool isprime(int p)
{
	int l = 0;
	int r = primes.size() - 1;

	while (l != r)
	{
		int mid = (l + r) / 2;

		if (primes[mid] < p)
			l = mid + 1;
		else
			r = mid;
	}

	if (primes[l] == p)
		return true;

	return false;
}

int reverse(int p)
{
	int aux = 0;
	while (p)
	{
		aux *= 10;
		aux += p % 10;
		p /= 10;
	}

	return aux;
}

int main()
{
	sieve();

	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (!isprime(n))
			printf("%d is not prime.\n", n);
		else if (isprime(reverse(n)) && n != reverse(n))
			printf("%d is emirp.\n", n);
		else
			printf("%d is prime.\n", n);
	}
}