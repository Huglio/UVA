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

int getDiagonals(int x)
{
	if (x <= 2) return 0;
	if (x == 3) return 1;

	int diags = x - 2;

	int resp = (1 + diags) * diags - diags;

	return resp;
}

int main()
{
	int TC; scanf("%d", &TC);

	while (TC--)
	{
		int x; scanf("%d", &x);

		if (x <= 1)
			printf("%.3lf\n", 0.000);
		else
		{
			int slides = getDiagonals(x);
			double resp = ((x * x) - slides) + (slides * sqrt(2));

			printf("%.3lf\n", resp);
		}

		if (TC)
			printf("\n");
	}
}