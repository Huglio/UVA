#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

vector<int> V[2500];
bitset<2500>Check;
queue<int> q;

pair<int, int> BFS(int start)
{
	Check.reset();
	
	queue<int> q;
	q.push(start);
	Check[start] = true;
	
	int Day_Boom = 0;
	int Nodes_Boom = 0;
	
	int Day = 1;
	int Nodes_to_next = 0;
	int Nodes_left = 0;
	
	while(!q.empty())
	{
		int r = q.front(); q.pop();
		
		
		for(int i = 0; i < (int)V[r].size(); i++)
		{
			if(!Check[V[r][i]])
			{
				
				q.push(V[r][i]);
				Check[V[r][i]] = true;
				Nodes_to_next++;
			}
		}
		
		if(Nodes_to_next > Nodes_Boom)
		{
			Day_Boom = Day;
			Nodes_Boom = Nodes_to_next;
		}
		
		Nodes_left--;
		if(Nodes_left <= 0)
		{
			Day++;
			Nodes_left = Nodes_to_next;
			Nodes_to_next = 0;
		}	
	}
	
	return pair<int, int> (Nodes_Boom, Day_Boom);
}

int main()
{
	int E; scanf("%d", &E);
	for(int i = 0; i < E; i++)
	{
		int Friends; scanf("%d", &Friends);
		for(int j = 0; j < Friends; j++)
		{
			int x; scanf("%d", &x);
			V[i].push_back(x);
		}
	}
		
	int Tests; scanf("%d", &Tests);
	for(int i = 0; i < Tests; i++)
	{
		int Start; scanf("%d", &Start);
		
		pair<int, int> R = BFS(Start);
		
		if(R.first != 0 || R.second != 0)
			printf("%d %d\n", R.first, R.second);
		else
			printf("0\n");
	}
}
