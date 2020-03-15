#include <stdio.h>
#include <vector>
#include <bitset>
#include <queue>
#include <cmath>

using namespace std;

#define ll long long int
#define MOD 10
#define ii pair<int, int>

vector<int> primes;
bitset<100010> bs;

void sieve()
{
	bs.set();
	
	for (ll i = 2; i < 100000; i++)
	{
		if(bs[i])
		{
			primes.push_back(i);
			for (ll j = i * i; j < 100000; j += i)
				bs[j] = 0;
		}
	}
}

int countDivs(int n)
{
	int divs = 1;
	for (int i = 0; i < (int)primes.size() && (ll)primes[i] * primes[i] <= n; i++)
	{
		int cnt = 0;
		while(n % primes[i] == 0)
		{
			cnt++;
			n /= primes[i];
		}
		
		divs *= (cnt + 1);
	}
	
	if(n != 1) divs *= 2;
	
	return divs;
}

int main()
{
	sieve();
	
	int TC; scanf("%d", &TC);
	
	while(TC--)
	{
		int l, u; scanf("%d %d", &l, &u);
		
		ii best = ii(l, countDivs(l));
		
		for (int i = l + 1; i <= u; i++)
		{
			
			int aux = countDivs(i);

			if(best.second < aux)
			{
				best.first = i;
				best.second = aux;
			}
		}
		
		printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, u, best.first, best.second);
	}
}
