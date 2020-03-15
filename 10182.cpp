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

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int at = 1;
		
		int x = 0;
		int y = 0;
		int add = 5;
		while (at + add <= n)
		{
			at += add;
			add += 6;
			
			x++, y--;
		}

		int aux = x + 1;
		for (int i = 0; i < aux && at != n; i++, at++, y++);
		for (int i = 0; i < aux - 1 && at != n; i++, at++, x--, y++);
		for (int i = 0; i < aux && at != n; i++, at++, x--);
		for (int i = 0; i < aux && at != n; i++, at++, y--);
		for (int i = 0; i < aux && at != n; i++, at++, x++, y--);
		for (int i = 0; i < aux - 1 && at != n; at++, i++, x++);

		printf("%d %d\n", x, y);
	}
}