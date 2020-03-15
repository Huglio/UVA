#include "pch.h"
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int main()
{
	freopen("Input.txt", "r", stdin);


	int N; cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		map<string, int> Meta;
		map<string, set<string>> Category;
		map<string, set<string>> CategoryCheck;
		vector<string> Order;

		int C; cin >> C;

		map<string, int> Ammount;
		set<string> Answer;

		for (int j = 0; j < C; j++)
		{
			string NewCategory; cin >> NewCategory;
			int x, y; cin >> x >> y;

			Order.push_back(NewCategory);
			Meta[NewCategory] = y;

			for (int k = 0; k < x; k++)
			{
				string word; cin >> word;
				Category[word].insert(NewCategory);
			}

			if (y == 0)
				Answer.insert(NewCategory);
		}

		cin.ignore();

		string sentence;
		getline(cin, sentence);
		while (sentence.length())
		{
			string word = "";
			for (int j = 0; j < sentence.length(); j++)
			{
				if (tolower(sentence[j]) >= 'a' && tolower(sentence[j]) <= 'z')
					word += (sentence[j]);
				else
					if (word.length())
					{
						map<string, set<string>>::iterator it = Category.find(word);
						if (it != Category.end())
						{
							for (set<string>::iterator iter = it->second.begin(); iter != it->second.end(); iter++)
							{
								if (CategoryCheck[*iter].find(word) == CategoryCheck[*iter].end())
								{
									CategoryCheck[*iter].insert(word);
									if (Ammount[*iter]++ == Meta[*iter] - 1)
										Answer.insert(*iter);
								}
							}
						}

						word = "";
					}
			}

			if (word.length())
			{
				map<string, set<string>>::iterator it = Category.find(word);
				if (it != Category.end())
				{
					for (set<string>::iterator iter = it->second.begin(); iter != it->second.end(); iter++)
					{
						if (CategoryCheck[*iter].find(word) == CategoryCheck[*iter].end())
						{
							CategoryCheck[*iter].insert(word);
							if (Ammount[*iter]++ == Meta[*iter] - 1)
								Answer.insert(*iter);
						}
					}
				}
			}

			getline(cin, sentence);
		}

		vector<string>Victory;
		if (Answer.size())
		{
			for (int j = 0; j < Order.size(); j++)
			{
				if (Answer.find(Order[j]) != Answer.end())
					Victory.push_back(Order[j]);
			}

			cout << Victory[0];
			for (int j = 1; j < Victory.size(); j++)
				cout << "," << Victory[j];
			cout << endl;
		}
		else
			cout << "SQF Problem." << endl;
	}
}