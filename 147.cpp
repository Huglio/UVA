#include "pch.h"

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define inf 1000000

int main()
{
	freopen("Input.txt", "r", stdin);

	int coins[11] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };

	float x;
	while (cin >> x && (int)round(x * 100))
	{
		int s = (int)round(x * 100);

		long long int pd[30010];
		for (int i = 0; i <= s; i++) pd[i] = 0;

		pd[0] = 1;
		for (int j = 0; j < 11; j++)
			for (int i = 0; i <= s; i++)
				if (coins[j] <= i)
					pd[i] += pd[i - coins[j]];

		printf("%6.2f%17lld\n", x, pd[s]);
	}
}