#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <iostream>

using namespace std;

#define ll long long int
#define mult(a, b) (((a % mod) * (b % mod)) % mod)
#define sum(a, b) (((a % mod) + (b % mod)) % mod)

vector<int> primes;
bitset<20000010> bs;
int mod = 10;

void sieve()
{
	bs.set();
	
	for (ll i = 2; i <= 20000000; i++)
	{
		if(bs[i])
		{
			primes.push_back(i);
			
			for (ll j = i * i; j <= 20000000; j += i)
				bs[j] = 0;
		}
	}
}

int power(int n, int e)
{
	ll r = 1;
	while(e > 0)
	{
		if(e % 2) r = mult(r, n);
		n = mult(n, n);
		e /= 2;
	}
	return r;
}

int main()
{
	sieve();
	

	int n, m;
	int factors[1300000]; memset(factors, 0, sizeof(factors));

	while(scanf("%d %d", &n, &m) != EOF)
	{
		m = n - m;
		int lastprime = 2;
		for(int i = 0; i < (int)primes.size(); i++)
		{
			lastprime = primes[i];
			
			ll aux = primes[i];
			
			while(aux <= n)
			{
				factors[i] += n / aux;
				factors[i] -= m / aux;
				aux *= primes[i];
			}
		}
		
		ll zeros = min(factors[0], factors[2]);
		factors[0] -= zeros;
		factors[2] -= zeros;
		
		int resp = 1;
		for (int i = 0; i < (int)primes.size() && primes[i] <= lastprime; i++)
		{
			resp = mult(resp, power(primes[i], factors[i]));

			factors[i] = 0;
		}
		
		printf("%d\n", resp);
	}
}
