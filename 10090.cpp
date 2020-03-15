#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;

#define ll long long int

ll x, y, d;
void extendedEuclid(ll a, ll b)
{
	if (b == 0) {x = 1; y = 0; d = a; return; }
	extendedEuclid(b, a % b);
	
	ll x1 = y;
	ll y1 = x - (a / b) * y;
	
	x = x1;
	y = y1;
}

int main()
{
	ll n;
	while(scanf("%lld", &n) && n)
	{
		ll c1, n1; scanf("%lld %lld", &c1, &n1);
		ll c2, n2; scanf("%lld %lld", &c2, &n2);
		
		extendedEuclid(n1, n2);
		
		if(n % d)
			printf("failed\n");
		else
		{
			x = x * (n / d);
			y = y * (n / d);
			
			ll minn = ceil(x / (double(-n2) / d));
			ll maxn = floor(y / (double(n1) / d));
			
			if(minn > maxn)
				printf("failed\n");
			else
			{
				ll cost1 = c1 * (x + n2 / d * minn) + c2 * (y - n1 / d * minn);
				ll cost2 = c1 * (x + n2 / d * maxn) + c2 * (y - n1 / d * maxn);
				
				if(cost1 < cost2)
					printf("%lld %lld\n", x + n2 / d * minn, y - n1 / d * minn);
				else
					printf("%lld %lld\n", x + n2 / d * maxn, y - n1 / d * maxn);
			}
		}
		
	}
}
