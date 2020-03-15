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
#define inf 1000000000
#define BOUNDS 1000000
#define ll long long int
#define ii pair<int, int>
//#define MOD 10

#define sum(a, b) (ll)(((ll)(a % MOD) + (ll)(b % MOD)) % MOD)
#define mult(a, b) (((ll)(a % MOD) * (ll)(b % MOD)) % MOD)
#define goldenratio ((double)(1 + sqrt(5)) / 2)
#define binet(a) (ll)round((((double)pow(goldenratio, a) - (double)pow(-goldenratio, -a)) / sqrt(5)))

#define valid(a, b) (a >= 0 && a < R && b >= 0 && b < C && row[a] && column[b])

int f(string str, int mod)
{
	if (str.size() == 0)
		return 0;

	if (str.size() < 5)
		return stoi(str) % mod;

	string aux = "";
	for (int i = (int)str.size() - 5; i < (int)str.size(); i++)
		aux += str[i];
	str.erase(str.end() - 5, str.end());

	int p1 = stoi(aux) % mod;
	int p2 = ((100000 % mod) * (f(str, mod) % mod)) % mod;

	return ((p1 % mod) + (p2 % mod)) % mod;
}

int gcd(int a, int b)
{
	if (b == 0) return a;

	return gcd(b, a % b);
}

int mmc(int a, int b)
{
	return a * (b / gcd(a, b));
}

int main()
{
	int TC; scanf("%d", &TC);

	while (TC--)
	{
		string str; cin >> str;

		int n; scanf("%d", &n);
		int divisor = 1;
		for (int i = 0; i < n; i++)
		{
			int x; scanf("%d", &x);
			divisor = mmc(divisor, x);
		}

		cout << str << " - ";

		if (f(str, divisor) == 0)
			cout << "Wonderful." << endl;
		else
			cout << "Simple." << endl;
	}
}