#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

int Diff(string a, string b)
{
	int counter = 0;
	for(int i = 0; i < a.length(); i++)
	{
		if(a[i] != b[i])
			counter++;
	}
	return counter;
}

int main()
{	
	freopen("Input.txt", "r", stdin);

	int N; cin >> N;
	
	for(int k = 0; k < N; k++)
	{
		string str;
		set<string> Words[10];
		while(cin >> str && str[0] != '*')
		{
 			Words[str.length()-1].insert(str);
		}
		cin.ignore();
		while(getline(cin, str) && str.length() != 0)
		{
			stringstream s(str);
			string Start;
			string End;
			
			s >> Start;
			s >> End;
			
			
			int Moves = 0;
			int Nodes_to_next = 0;
			int Nodes_left = 0;
			
			set<string> Check;
			queue<string> q;
			q.push(Start);
			Check.insert(Start);			
			
			bool Done = false;
			while(!q.empty() && !Done)
			{
				string r = q.front(); q.pop();
				
				if(r == End)
				{
					Done = true;
				}
				else
				{
					for(set<string>::iterator It = Words[Start.length()-1].begin(); It != Words[Start.length()-1].end(); It++)
					{
						
						if(Diff(r, *It) == 1 && Check.find(*It) == Check.end())
						{
							
							Check.insert(*It);
							q.push(*It);
							Nodes_to_next++;
						}
					}
					
					Nodes_left--;
					if(Nodes_left <= 0)
					{
						Moves++;
						Nodes_left = Nodes_to_next;
						Nodes_to_next = 0;
					}
				}
			}
			
			cout << Start << " " << End << " " << Moves << endl;
		}
	}
}
