#include "pch.h"

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#define inf 1e9

int main()
{
	freopen("Input.txt", "r", stdin);

	double prices[25];
	int ammount[25];
	ammount[0] = 1;

	int TC = 1;
	int n;
	while (scanf("%lf %d", &prices[0], &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d %lf", &ammount[i], &prices[i]);

		double resp[210];
		resp[0] = 0;

		for (int i = 1; i <= 200; i++)
		{
			resp[i] = inf;

			for (int j = 0; j <= n; j++)
				if (i >= ammount[j])
					resp[i] = min(resp[i], prices[j] + resp[i - ammount[j]]);
		}

		cin.ignore();
		string str; getline(cin, str);
		stringstream ss(str);

		printf("Case %d:\n", TC++);
		while (ss >> str)
		{
			double cost = inf;
			for (int k = stoi(str); k <= 200; k++)
				cost = min(cost, resp[k]);

			printf("Buy %d for $%.2lf\n", stoi(str), cost);
		}
	}
}