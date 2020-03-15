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
//#define MOD 10

#define sum(a, b) (ll)(((ll)(a % MOD) + (ll)(b % MOD)) % MOD)
#define mult(a, b) (((ll)(a % MOD) * (ll)(b % MOD)) % MOD)
#define goldenratio ((double)(1 + sqrt(5)) / 2)
#define binet(a) (ll)round((((double)pow(goldenratio, a) - (double)pow(-goldenratio, -a)) / sqrt(5)))

#define valid(a, b) (a >= 0 && a < R && b >= 0 && b < C && row[a] && column[b])

ll power(ll n, ll e) {
	ll r = 1;
	while (e > 0) {
		if (e % 2) r *= n;
		n *= n;
		e /= 2;
	}
	return r;
}

int main()
{
	string str;

	while (getline(cin, str))
	{
		vector<int> coeficients;
		vector<int> expoents;

		{
			stringstream ss(str);

			while (ss >> str)
				coeficients.push_back(stoi(str));
		}

		{
			getline(cin, str);
			stringstream ss(str);

			while (ss >> str)
				expoents.push_back(stoi(str));
		}

		vector<ll> resp;

		for (int i = 0; i < (int)expoents.size(); i++)
		{
			ll aux = 0;
			for (int j = int(coeficients.size()) - 1, e = 0; j >= 0; j--, e++)
				aux += coeficients[j] * power(expoents[i], e);
			resp.push_back(aux);
		}

		printf("%lld", resp[0]);
		for (int i = 1; i < int(resp.size()); i++)
			printf(" %lld", resp[i]);
		printf("\n");
	}
}