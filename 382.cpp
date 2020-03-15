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
#include <queue>
#include <string>
#include <set>
#include <cmath>
#include <stack>
#include <limits.h>

using namespace std;

#define inf 100000000
#define ll long long int
#define ii pair<int, int>
#define MOD 1000000007

#define sum(a, b) (ll)(((ll)(a % MOD) + (ll)(b % MOD)) % MOD)
#define mult(a, b) (ll)(((ll)(a % MOD) * (ll)(b % MOD)) % MOD)

int main()
{
	freopen("Input.txt", "r", stdin);

	printf("PERFECTION OUTPUT\n");

	int x;
	while (scanf("%d", &x) && x)
	{
		int sum = 0;

		int i;
		for (i = 2; i * i < x; i++)
			if (x % i == 0)
				sum += (i + x / i);

		if (x != 1) sum += 1;
		if (i * i == x) sum += i;

		if (sum == x)
			printf("%5d  PERFECT\n", x);
		else if (sum < x)
			printf("%5d  DEFICIENT\n", x);
		else
			printf("%5d  ABUNDANT\n", x);
	}

	printf("END OF OUTPUT\n");
}