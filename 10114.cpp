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

int main()
{
	freopen("Input.txt", "r", stdin);

	int months, k;
	float payment, owed;
	while (cin >> months >> payment >> owed >> k && months > 0)
	{
		float car = owed + payment;
		float depre[110];

		int aux = 0;
		for (int i = 0; i < k; i++, aux++)
		{
			int x; float y; cin >> x >> y;

			while (aux < x)
				depre[aux++] = depre[aux - 1];

			depre[aux] = y;
		}

		while (aux <= months)
			depre[aux++] = depre[aux - 1];

		int i;

		//printf("car: %lf, depre: %lf\n", car, depre[0]);
		car = car * (1 - depre[0]);

		payment = owed / months;
		//printf("car starts with %lf\n", car);
		for (i = 1; i <= months && owed > car; i++)
		{
			//printf("depre is %lf\n", depre[i]);

			owed -= payment;
			car = car - (car * depre[i]);

			//printf("i: %d, car: %lf, owed: %lf\n", i, car, owed);
		}
		i--;

		if (i == 1)
			printf("1 month\n");
		else
			printf("%d months\n", i);
	}
}