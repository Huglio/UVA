#include "pch.h"

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define inf 1000000
#define ii pair<int, int>

int read(int* vet, string str)
{
	stringstream ss(str);
	string word;

	int cnt = 0;
	while (ss >> word)
		vet[cnt++] = stoi(word);

	return cnt;
}

int main()
{
	freopen("Input.txt", "r", stdin);
	
	int vet[30];

	int n;
	cin >> n;

	while (n)
	{
		int order[30];
		for (int i = 0; i < n; i++)
			cin >> order[i];

		cin.ignore();
		string str;
		while (getline(cin, str) && read(vet, str) != 1)
		{
			ii input[30];
			for (int i = 0; i < n; i++)
				input[i] = ii(vet[i], i);

			sort(input, input + n);

			for (int i = 0; i < n; i++)
				vet[i] = order[input[i].second];

			vector<int> V;

			for (int i = 0; i < n; i++)
			{
				if (V.empty() || V.back() < vet[i])
					V.push_back(vet[i]);
				else
				{
					int l = 0;
					int r = V.size() - 1;

					while (l != r)
					{
						int mid = (l + r) / 2;

						if (V[mid] < vet[i])
							l = mid + 1;
						else
							r = mid;
					}

					V[l] = vet[i];
				}
			}

			printf("%d\n", (int)V.size());
		}

		n = str.length() ? vet[0] : 0;
	}
}