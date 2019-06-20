#include "pch.h"
#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

int main()
{
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);

	set<string> Words;
	
	string str;
	string Compose = "";
	while (getline(cin, str))
	{
		string toadd = "";
		for (int i = 0; str[i]; i++)
		{
			if ((tolower(str[i]) >= 'a' && tolower(str[i]) <= 'z' || str[i] == '-') && i + 1 != str.length())
				toadd += tolower(str[i]);
			else
			{
				if(i + 1 == str.length() && tolower(str[i]) >= 'a' && tolower(str[i]) <= 'z')
					toadd += tolower(str[i]);

				if (Compose.size())
				{
					Compose += toadd;

					if (!(i == (int)str.length() - 1 && str[i] == '-'))
					{
						Words.insert(Compose);
						Compose = "";
					}
				}
				else if (i == (int)str.length() - 1 && str[i] == '-')
					Compose = toadd;
				else
				{
					if(toadd.size())
						Words.insert(toadd);
				}

				toadd = "";
			}
		}

		if (toadd.size())
		{
			if (Compose.size())
			{
				Compose += toadd;
				Words.insert(Compose);
			}
			else
				Words.insert(toadd);
		}
	}


	for (set<string>::iterator it = Words.begin(); it != Words.end(); it++)
	{
		cout << *it << endl;
	}
}