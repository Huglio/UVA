#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

int main()
{
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);

	int t; cin >> t;

	for (int k = 0; k < t; k++)
	{
		cin.ignore();
		string name;
		getline(cin, name);

		int m, n, b;
		cin >> m >> n >> b;

		map<string, int> M;

		for (int i = 0; i < m; i++)
		{
			string ingredient; cin >> ingredient;
			int value; cin >> value;
			M[ingredient] = value;
		}

		priority_queue<pair<int, string>, vector<pair<int, string> >, greater<pair<int, string> > >pq;

		for (int j = 0; j < n; j++)
		{
			cin.ignore();
			string recipe; getline(cin, recipe);
			int x; cin >> x;

			int total = 0;
			for (int i = 0; i < x; i++)
			{
				string ingredient; cin >> ingredient;
				int c; cin >> c;

				total += c * M[ingredient];
			}

			if (total <= b)
				pq.push(pair<int, string>(total, recipe));
		}

		for (int i = 0; name[i]; i++)
			cout << (char)toupper(name[i]);
		cout << endl;

		if (pq.empty())
			cout << "Too expensive!" << endl;
		else while (!pq.empty())
		{
			cout << pq.top().second << endl;
			pq.pop();
		}
		cout << endl;

	}
}