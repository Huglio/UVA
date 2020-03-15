#include "pch.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
	freopen("Input.txt", "r", stdin);

	int n;
	while (cin >> n && n)
	{

		string turned = "+x";
		for (int i = 0; i < n - 1; i++)
		{
			string str; cin >> str;

			if (turned == "+x" && str != "No")
				turned = str;
			else if (turned == "-x")
			{
				if (str == "+y")
					turned = "-y";
				else if (str == "-y")
					turned = "+y";
				else if (str == "+z")
					turned = "-z";
				else if (str == "-z")
					turned = "+z";
			}
			else if (turned == "+y")
			{
				if (str == "+y")
					turned = "-x";
				else if (str == "-y")
					turned = "+x";
			}
			else if (turned == "-y")
			{
				if (str == "+y")
					turned = "+x";
				else if (str == "-y")
					turned = "-x";
			}
			else if (turned == "+z")
			{
				if (str == "+z")
					turned = "-x";
				else if (str == "-z")
					turned = "+x";
			}
			else if (turned == "-z")
			{
				if (str == "+z")
					turned = "x";
				else if (str == "-z")
					turned = "-x";
			}
		}

		cout << turned << endl;
	}
}