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

#define inf 100000000
#define BOUNDS 1000000
#define ll long long int
#define ii pair<int, int>
#define MOD 1000000007

#define sum(a, b) (ll)(((ll)(a % MOD) + (ll)(b % MOD)) % MOD)
#define mult(a, b) (ll)(((ll)(a % MOD) * (ll)(b % MOD)) % MOD)

#define valid(a, b) (a >= 0 && a < R && b >= 0 && b < C && row[a] && column[b])

int main()
{
	string str;
	while (getline(cin, str))
	{
		string buffer = "";
		list<string> resp;

		bool home = false;
		for (int i = 0; i < (int)str.length(); i++)
		{
			if (str[i] != '[' && str[i] != ']')
				buffer += str[i];
			else
			{
				if (home)
					resp.push_front(buffer);
				else
					resp.push_back(buffer);

				if (str[i] == '[')
					home = true;
				else
					home = false;

				buffer = "";
			}
		}

		if (home)
			resp.push_front(buffer);
		else
			resp.push_back(buffer);

		while (!resp.empty())
		{
			cout << resp.front();
			resp.pop_front();
		}
		cout << endl;
	}
}