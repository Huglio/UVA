#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;


vector<int> V;

int pd[30][220];

bool f(int index, int sum)
{
	if(sum == 0) return true;
	if(sum < 0) return false;
	if(index >= (int)V.size()) return false;
	if(pd[index][sum] != -1) return pd[index][sum];
	
	bool resp = f(index + 1, sum) || f(index + 1, sum - V[index]);
	
	return pd[index][sum] = resp;
}

int main()
{
	int TC; scanf("%d", &TC);
	
	cin.ignore();
	while(TC--)
	{		
		memset(pd, -1, sizeof(pd));
		V.clear();
		
		string str; getline(cin, str);
		stringstream ss(str);
		
		int total = 0;
		while(ss >> str)
		{
			V.push_back(stoi(str));
			total += stoi(str);
		}
		
		if(total%2 == 0 && f(0, total/2))
			printf("YES\n");
		else
			printf("NO\n");
	}
}
