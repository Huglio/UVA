#include "pch.h"

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define MOD 1000000
#define ll long long int

ll x[1000010];

ll soma(ll a, ll b)
{
	ll resp = (a % MOD + b % MOD) % MOD;

	return resp < 0 ? resp + MOD : resp;
}

ll f(int n)
{
	if (x[n] != -1) return x[n];

	return x[n] = soma(soma(f(n - sqrt(n)), f(log(n))), f(n * sin(n) * sin(n)));

	//return f(round(n - sqrt(n))) + f(round((log(n))) + f(round(n * sin(n) * sin(n)));
}

int main()
{
	memset(x, -1, sizeof(x));
	x[0] = 1;

	int n;
	while (scanf("%d", &n) && n != -1)
	{
		printf("%lld\n", f(n));
	}
}