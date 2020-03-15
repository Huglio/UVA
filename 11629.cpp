#include "pch.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	freopen("Input.txt", "r", stdin);

	int P, G;
	cin >> P >> G;

	map<string, int> Table;

	for (int i = 0; i < P; i++)
	{
		string str; cin >> str;
		float value; cin >> value;

		Table[str] = (int)(value*10);
	}

	for (int i = 1; i <= G; i++)
	{
		string str;
		
		cin >> str;
		int TOTAL = Table[str];

		string op; cin >> op;
		while (op == "+")
		{
			cin >> str;
			TOTAL += Table[str];

			cin >> op;
		}

		int guess; cin >> guess;
		bool correct = false;

		if (op == "<")
			correct = TOTAL < (guess*10);
		else if (op == ">")
			correct = TOTAL > (guess*10);
		else if (op == "<=")
			correct = TOTAL <= (guess*10);
		else if (op == ">=")
			correct = TOTAL >= (guess*10);
		else if (op == "=")
			correct = TOTAL == (guess*10);

		if (correct)
			cout << "Guess #" << i << " was correct." << endl;
		else
			cout << "Guess #" << i << " was incorrect." << endl;
	}
}