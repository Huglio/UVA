#include "pch.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	freopen("Input.txt", "r", stdin);

	map<string, string> Table;
	int N; cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		string key, value;
		getline(cin, key);
		getline(cin, value);
		Table[key] = value;
	}

	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		string key;
		getline(cin, key);

		cout << Table[key] << endl;
	}
}