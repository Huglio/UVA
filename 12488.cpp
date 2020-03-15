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

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int start[30];
		int vet[30];

		for (int i = 0; i < n; i++)
		{
			int x; scanf("%d", &x);
			start[x] = i;
		}

		for (int i = 0; i < n; i++)
		{
			int x; scanf("%d", &x);
			vet[i] = start[x];
		}

		int resp = 0;
		for (int i = 0; i < n; i++)
			for (int j = i - 1; j >= 0; j--)
				if (vet[j] > vet[i])
					resp++;

		printf("%d\n", resp);
	}
}