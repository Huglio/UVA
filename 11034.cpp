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
	int TC; scanf("%d", &TC);

	while (TC--)
	{
		int l, m; scanf("%d %d", &l, &m);

		l = l * 100;
		queue<int> left;
		queue<int> right;

		for (int i = 0; i < m; i++)
		{
			int x; string str; cin >> x >> str;
			if (str == "left")
				left.push(x);
			else
				right.push(x);
		}

		int resp = 0;
		bool at_left = true;
		while (!left.empty() || !right.empty())
		{
			int cargo = 0;
			resp++;

			if (at_left)
			{
				while (!left.empty() && left.front() + cargo <= l)
				{
					cargo += left.front();
					left.pop();
				}
			}
			else
			{
				while (!right.empty() && right.front() + cargo <= l)
				{
					cargo += right.front();
					right.pop();
				}
			}

			at_left = !at_left;
		}

		printf("%d\n", resp);
	}
}