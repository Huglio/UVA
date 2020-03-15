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
#define MOD 10

#define sum(a, b) (ll)(((ll)(a % MOD) + (ll)(b % MOD)) % MOD)
#define mult(a, b) (((ll)(a % MOD) * (ll)(b % MOD)) % MOD)
#define goldenratio ((double)(1 + sqrt(5)) / 2)
#define binet(a) (ll)round((((double)pow(goldenratio, a) - (double)pow(-goldenratio, -a)) / sqrt(5)))

#define valid(a, b) (a >= 0 && a < R && b >= 0 && b < C && row[a] && column[b])

int power(int n, int e)
{
	if (e == 1) return n;
	if (e == 0) return 1;

	int resp = power(n, e / 2);
	resp = resp * resp;

	if (e % 2) resp = resp * n;

	return resp;
}

int main()
{
	string str;
	while (cin >> str && !(str.length() == 1 && str[0] == '0'))
	{
		int result = 0;
		for (int i = str.length() - 1, cnt = 1; i >= 0; i--, cnt++)
			if (str[i] - '0')
				result += (str[i] - '0') * (power(2, cnt) - 1);

		cout << result << endl;
	}
}