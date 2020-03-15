#include "pch.h"

#include <iostream>
#include <cstring>
#include <bitset>
#include <vector>
#include <map>

using namespace std;

map<vector<int>, bool> dp;

bool f(vector<int> V)
{
	if ((int)V.size() == 1)
		return V[0] > 1 ? true : false;

	if (dp.find(V) != dp.end()) return dp[V];

	for (int i = 0; i < (int)V.size(); i++)
	{
		if (V[i] == 1) continue;

		vector<int> Aux = V;

		if (i && i != (int)V.size() - 1)
		{
			int x = Aux[i - 1] + Aux[i + 1];

			Aux.erase(Aux.begin() + (i - 1), Aux.begin() + (i + 2));
			Aux.insert(Aux.begin() + (i - 1), x);
		}
		else
			Aux.erase(Aux.begin() + i);

		if (f(Aux))
			return dp[V] = true;
	}

	return dp[V] = false;
}

int main()
{
	freopen("Input.txt", "r", stdin);

	int TC; cin >> TC;

	while (TC--)
	{
		string str; cin >> str;
		
		vector<int> V;
		int last = -1;
		for (int i = 0; i < (int)str.length() - 1; i++)
		{
			if (str[i] != str[i + 1])
			{
				V.push_back(i - last);
				last = i;
			}
		}
		V.push_back((int)str.length() - last - 1);

		if (f(V))
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}
}