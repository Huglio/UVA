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
#define BOUNDS 1000000
#define ll long long int
#define ii pair<int, int>
#define MOD 1000000007

#define sum(a, b) (ll)(((ll)(a % MOD) + (ll)(b % MOD)) % MOD)
#define mult(a, b) (ll)(((ll)(a % MOD) * (ll)(b % MOD)) % MOD)

#define valid(a, b) (a >= 0 && a < R && b >= 0 && b < C && row[a] && column[b])

int gcd(int a, int b)
{
	if (b == 0) return a;

	return gcd(b, a%b);
}

int main()
{
	int n; scanf("%d", &n);

	cin.ignore();
	while (n--)
	{
		string str; getline(cin, str);
		stringstream ss(str);

		int vet[110], cnt = 0;
		while (ss >> str)
			vet[cnt++] = stoi(str);
	
		int resp = 1;
		for (int i = 0; i < cnt; i++)
			for (int j = i + 1; j < cnt; j++)
				resp = max(resp, gcd(vet[i], vet[j]));

		printf("%d\n", resp);
	}
}