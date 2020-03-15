#include <stdio.h>
#include <map>

using namespace std;

#define ll long long int

int sum(ll a, ll b, int mod)
{
	ll resp = (((a % mod) + (b % mod)) % mod);
	return (int)resp;
}

int mult(ll a, ll b, int mod)
{
	ll resp = (((a % mod) * (b % mod)) % mod);
	return (int)resp;
}

int main()
{
	freopen("in.txt", "r", stdin);
	
	ll n, a, b;
	while(scanf("%lld", &n) && n)
	{
		scanf("%lld %lld", &a, &b);
		
		map<ll, ll> MAP;
		ll cnt = 1;
		
		ll x = 0;
		while(MAP.find(x) == MAP.end())
		{
			MAP[x] = cnt++;
			x = (sum(mult(mult(a, x, n), x, n), b, n));
		}
		
		printf("%lld\n", n - (cnt - MAP[x]));
	}
}
