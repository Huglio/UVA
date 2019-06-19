#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main()
{
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);

	int k; cin >> k;
	while (k--)
	{
		map<string, string> Dictionary;

		string input; cin >> input;
		string key = "";
		string value = "";
		bool onkey = true;
		if(input.length() > 2)
			for (int i = 1; i < (int)input.length(); i++)
			{
				if (input[i] == ',' || input[i] == '}')
				{
					onkey = true;
					Dictionary[key] = value;
					key = "";
					value = "";
				}
				else if (input[i] == ':')
					onkey = false;
				else
				{
					if (onkey)
						key += input[i];
					else
						value += input[i];
				}
			}

		set<string> Add;
		set<string> Change;

		cin >> input;
		key = "";
		value = "";
		onkey = true;
		if(input.length() > 2)
		for (int i = 1; i < (int)input.length(); i++)
		{
			if (input[i] == ',' || input[i] == '}')
			{
				onkey = true;
				if (Dictionary.find(key) != Dictionary.end())
				{
					if (Dictionary[key] != value)
						Change.insert(key);
					Dictionary.erase(key);
				}
				else
				{
					Add.insert(key);
				}
				key = "";
				value = "";
			}
			else if (input[i] == ':')
				onkey = false;
			else
			{
				if (onkey)
					key += input[i];
				else
					value += input[i];
			}
		}

		if (Add.size())
		{
			set<string>::iterator it = Add.begin();
			cout << "+" << *it;
			for (it++; it != Add.end(); it++)
				cout << "," << *it;
			cout << endl;
		}
		if (Dictionary.size())
		{
			map<string, string>::iterator it = Dictionary.begin();
			cout << "-" << it->first;
			for (it++; it != Dictionary.end(); it++)
				cout << "," << it->first;
			cout << endl;
		}
		if (Change.size())
		{
			set<string>::iterator it = Change.begin();
			cout << "*" << *it;
			for (it++; it != Change.end(); it++)
				cout << "," << *it;
			cout << endl;
		}

		if (!Add.size() && !Dictionary.size() && !Change.size())
			cout << "No changes" << endl;
		cout << endl;
	}
}