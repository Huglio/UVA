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

bitset<1010> bs;
vector<int> primes;

void sieve()
{
	bs.set();

	for (ll i = 2; i <= 1000; i++)
	{
		if (bs[i])
		{
			primes.push_back(i);

			for (ll j = i * i; j <= 1000; j += i)
				bs[j] = 0;
		}
	}
}

int power(int n, int e)
{
	if (e == 1) return n;
	if (e == 0) return 1;

	int resp = power(n, e / 2);
	resp = resp * resp;

	if (e % 2) resp = resp * n;

	return resp;
}

int main()
{
	sieve();

	string str, str2;
	while (getline(cin, str) && !(str.length() == 1 && str[0] == '0'))
	{
		stringstream ss(str);
		int number = 1;

		while (ss >> str >> str2)
			number *= power(stoi(str), stoi(str2));

		number--;
		stack<int> resp;
		for (int i = 0; i < int(primes.size()) && (ll)primes[i] * primes[i] <= number; i++)
		{
			if (number % primes[i] == 0)
			{
				int cnt = 0;
				while (number % primes[i] == 0)
				{
					cnt++;
					number /= primes[i];
				}

				resp.push(cnt);
				resp.push(primes[i]);
			}
		}

		if (number > 1)
		{
			resp.push(1);
			resp.push(number);
		}

		printf("%d", resp.top()); resp.pop();

		while (!resp.empty())
		{
			printf(" %d", resp.top());
			resp.pop();
		}
		printf("\n");
	}
}