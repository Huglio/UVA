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
#define MOD 2000000000000

#define sum(a, b) (ll)(((ll)(a % MOD) + (ll)(b % MOD)) % MOD)
#define mult(a, b) (ll)(((ll)(a % MOD) * (ll)(b % MOD)) % MOD)
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
	int TC;
	while (scanf("%d", &TC) && TC != -1)
	{
		while (TC--)
		{
			int depth, k; scanf("%d %d", &depth, &k);

			int resp = power(2, depth - 1);

			while (depth--)
			{
				if (k % 2 == 0)
					resp += power(2, depth - 1);
				
				k = (k / 2 + k % 2);
			}

			printf("%d\n", resp);
		}
	}
}