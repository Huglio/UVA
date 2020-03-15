#include "pch.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define inf 1000000
#define ll long long int

int n, k, m;

ll pd[60][60][60][5];

ll f(int index, int cnt, int bars, int on)
{
	if (cnt == m + 1) return 0;
	if (bars > k) return 0;
	if (index >= n) return bars == k ? 1 : 0;

	if (pd[index][cnt][bars][on] != -1) return pd[index][cnt][bars][on];

	ll resp = f(index + 1, cnt + 1, bars, on) + f(index + 1, 1, bars + 1, (on + 1) % 2);

	return pd[index][cnt][bars][on] = resp;
}

int main()
{
	while (scanf("%d %d %d", &n, &k, &m) != EOF)
	{
		memset(pd, -1, sizeof(pd));
		printf("%lld\n", f(1, 1, 1, 1));
	}
}