#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <string>
#include <cstring>

using namespace std;

vector<string> RESP;
vector<int> Variables;
vector<int> adjlist[30];
char Letters[30];
bool vis[30];
int in_edges[30];
int table[200];
int n;

vector<int> tmp;
void insertRESP()
{
	string str = "";
	str += Letters[tmp[tmp.size() - 1]];

	for (int i = (int)tmp.size() - 2; i >= 0; i--)
	{
		str += " "; 
		str += Letters[tmp[i]];
	}

	RESP.push_back(str);
}

void f(int index)
{
	//cout << "index: " << index << endl;

	for (int i = 0; i < n; i++)
	{
		if (in_edges[i] == 0 && !vis[i])
		{
			//cout << "size: " << adjlist[i].size() << endl;
			for (int v : adjlist[i])
			{
				//cout << "remove\n";
				in_edges[v]--;
			}

			tmp.push_back(i);
			vis[i] = 1;
			
			f(index + 1);

			vis[i] = 0;
			tmp.pop_back();

			for (int v : adjlist[i])
				in_edges[v]++;
		}
	}

	if (tmp.size() == n)
		insertRESP();
}

int main()
{
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int t; cin >> t;

	cin.ignore();
	while (t--)
	{
		cin.ignore();
		for (int i = 0; i < 30; i++) adjlist[i].clear();
		for (int i = 0; i < 30; i++) vis[i] = 0;
		memset(in_edges, 0, sizeof in_edges);
		Variables.clear();
		RESP.clear();

		string str; getline(cin, str);

		//cout << "read: " << str << endl;

		int cnt = 0;
		for (int i = 0; i < str.length(); i += 2)
		{
			Variables.push_back(str[i]);
			Letters[cnt] = str[i];
			table[str[i]] = cnt++;

			//cout << "table: " << table[str[i]] << endl;
		}

		//cout << "ooooooooook\n";

		n = Variables.size();

		getline(cin, str);

		//cout << "reading: "<< str << endl;

		for (int i = 0; i < str.length(); i += 4)
		{
			//cout << table[str[i + 2]] << " to " << table[str[i]] << endl;
			//cout << str[i + 2] << " to " << str[i] << endl;
			adjlist[table[str[i + 2]]].push_back(table[str[i]]);
			in_edges[table[str[i]]]++;

			//cout << "Edge++ in " << str[i] << endl;
		}

		f(0);

		if (RESP.size())
		{
			sort(RESP.begin(), RESP.end());

			for (int i = 0; i < RESP.size(); i++)
				cout << RESP[i] << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
		if (t)
			cout << endl;
	}
}