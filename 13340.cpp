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
#include <list>
#include <limits.h>

using namespace std;

#define sieveBOUND 1000010
#define inf 100000000
#define BOUNDS 1000000
#define ll long long int
#define ii pair<int, int>
#define MOD 1000000007

#define sum(a, b) (ll)(((ll)(a % MOD) + (ll)(b % MOD)) % MOD)
#define mult(a, b) (ll)(((ll)(a % MOD) * (ll)(b % MOD)) % MOD)
#define goldenratio ((double)(1 + sqrt(5)) / 2)
#define binet(a) (ll)round((((double)pow(goldenratio, a) - (double)pow(-goldenratio, -a)) / sqrt(5)))

#define valid(a, b) (a >= 0 && a < R && b >= 0 && b < C && row[a] && column[b])

int main()
{
	freopen("Input.txt", "r", stdin);

	int TC; scanf("%d", &TC);
	while (TC--)
	{
		int k; scanf("%d", &k);

		int paid[256]; memset(paid, 0, sizeof(paid));

		for (int i = 0; i < k; i++)
		{
			char c; int v; scanf(" %c %d", &c, &v);
			paid[int(c)] = v;

		}

		int lines; scanf(" %d", &lines);

		cin.ignore();
		int ammount = 0;
		while (lines--)
		{
			string str; getline(cin, str);

			for (int i = 0; i < (int)str.length(); i++)
				if (str[i] >= 0 && str[i] < 256)
					ammount += paid[int(str[i])];
		}

		printf("%d.%.2d$\n", ammount / 100, ammount % 100);
	}
}
