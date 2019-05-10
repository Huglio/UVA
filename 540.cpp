#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

class team_queue
{
	private:
	pair<int, int> Vector[200010];
	int lastindex = -1;
	
	public:
	void push(pair<int, int> ToPush)
	{
		int i; bool FTeam = false;
		for(i = lastindex + 1; i > 0 && !(FTeam && Vector[i].second == ToPush.second); i--)
		{
			if(Vector[i-1].second == ToPush.second)
				FTeam = true;
			Vector[i] = Vector[i-1];
		}
		
		Vector[i] = ToPush;
		lastindex++;
	}
	
	pair<int, int> front()
	{
		return Vector[lastindex];
	}
	
	void pop()
	{
		lastindex--;
	}
};

int main()
{
	team_queue q;
	
	int N;
	while(scanf("%d", &N) && N)
	{
		map<int, int> Team;
		
		for(int j = 0; j < N; j++)
		{
			int Members; scanf("%d", &Members);
			for(int i = 0; i < Members; i++)
			{
				int x; scanf("%d", &x);
				Team[x] = j;
			}
		}
		
		string Input;
		while(cin >> Input && Input != "STOP")
		{
			
		}
	}
}
