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

#define valid(a, b) (a >= 0 && a < R && b >= 0 && b < C && row[a] && column[b])

bool isbissexto(int n)
{
	if (n % 100 == 0 && n % 400)
		return false;

	return (n % 4 == 0);
}

pair<int, string> zodiacs[13] = {
	pair<int, string>(21, "aquarius"),
	pair<int, string>(20, "pisces"),
	pair<int, string>(21, "aries"),
	pair<int, string>(21, "taurus"),
	pair<int, string>(22, "gemini"),
	pair<int, string>(22, "cancer"),
	pair<int, string>(23, "leo"),
	pair<int, string>(22, "virgo"),
	pair<int, string>(24, "libra"),
	pair<int, string>(24, "scorpio"),
	pair<int, string>(23, "sagittarius"),
	pair<int, string>(23, "capricorn")
};

int d[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
	freopen("Input.txt", "r", stdin);

	int TC; scanf("%d", &TC);

	for (int k = 1; k <= TC; k++)
	{
		int months, days, years; scanf("%2d%2d%4d", &months, &days, &years);
		int add = 40 * 7;

		while (add)
		{
			days++;
			if (days > ((months == 2 && isbissexto(years)) ? 29 : d[months]))
			{
				months++;
				if (months > 12)
				{
					years++;
					months = 1;
				}
				days = 1;
			}

			add--;
		}

		printf("%d %.2d/%.2d/%d ", k, months, days, years);
		months--;

		if (days >= zodiacs[months].first)
			cout << zodiacs[months % 12].second;
		else
			cout << zodiacs[(months + 11) % 12].second;

		printf("\n");
	}
}