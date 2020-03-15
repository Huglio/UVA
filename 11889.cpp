#include <stdio.h>
#include <bitset>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long int

vector<int> primes;
bitset<10010> bs;

void sieve()
{
	bs.set();
	
	for (ll i = 2; i < 10000; i++)
	{
		if(bs[i])
		{
			primes.push_back(i);
			
			for (ll j = i * i; j < 10000; j += i)
				bs[j] = 0;
		}
	}
}

int power(int n, int e)
{
	int r = 1;
	while(e > 0)
	{
		if(e % 2) r *= n;
		n *= n;
		e /= 2;
	}
	return r;
}

int main()
{
	sieve();
	
	int TC; scanf("%d", &TC);
	
	while(TC--)
	{
		int A, C; scanf("%d %d", &A, &C);
		
		bool ok = true;
		int resp = 1;
		
		for (int i = 0; i < (int)primes.size() && ((ll)primes[i] * primes[i] <= A || (ll)primes[i] * primes[i] <= C) && ok; i++)
		{
			int cnta = 0;
			int cntc = 0;
			
			while(C % primes[i] == 0)
			{
				cntc++;
				C /= primes[i];
			}
			
			while(A % primes[i] == 0)
			{
				cnta++;
				A /= primes[i];
			}
			
			if(cnta > cntc)
				ok = false;
			else
			{
				if(cnta < cntc)
					resp *= power(primes[i], cntc);
			}
		}
		
		if(A > 1)
		{
			if(A != C)
				ok = false;
		}
		else if(C > 1)
			resp *= C;
		
		if(ok)
			printf("%d\n", resp);
		else
			printf("NO SOLUTION\n");
	}
}
