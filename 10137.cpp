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
	freopen("Input.txt", "r", stdin);

	int n;
	while (cin >> n && n)
	{
		ll vet[1010];
		for (int i = 0; i < n; i++)
		{
			double x; cin >> x;
			vet[i] = round(x * 100);
		}

		ll average = 0;
		for (int i = 0; i < n; i++)
			average += vet[i];
		
		int resto = (average % n);

		ll resp = 0;
		average = average / n;

		for (int i = 0; i < n; i++)
			if (vet[i] > average)
			{
				resp += (vet[i] - average);
				if (resto)
				{
					resto--;
					resp--;
				}
			}

		printf("$%.2lf\n", resp / 100.);
	}
}