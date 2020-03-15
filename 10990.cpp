#include <stdio.h>
#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

#define ll long long int

int pd[2000010];
double phi[2000010];
ll sum[2000010];
bitset<2000010> bs;

void sieve()
{
	bs.set();
	
	for (int i = 0; i < 2000010; i++)
		phi[i] = i;
	
	for (ll i = 2; i < 2000010; i++)
	{
		if(bs[i])
		{
			for (ll j = i; j < 2000010; j += i)
			{
				bs[j] = 0;
				phi[j] *= (1 - double(1) / i);
			}
		}
	}
}

int main()
{
	sieve();
	
	pd[1] = 0;
	for (int i = 2; i <= 2000000; i++)
		pd[i] = pd[int(round(phi[i]))] + 1;
		
	sum[1] = 0;
	for (int i = 2; i <= 2000000; i++)
		sum[i] = sum[i - 1] + pd[i];
		
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		int m, n; scanf("%d %d", &m, &n);
		
		printf("%lld\n", sum[n] - sum[m - 1]);
	}
	
}
