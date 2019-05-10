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
		for(i = lastindex + 1; i > 0 && !(FTeam && Vector[i-1].second != ToPush.second); i--)
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
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
		
	int N; int scenario = 0;
	while(scanf("%d", &N) && N)
	{
		team_queue q;

		scenario++;
		printf("Scenario #%d\n", scenario);
		
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
			if(Input == "ENQUEUE")
			{
				int x; scanf("%d", &x);
				q.push(pair<int, int>(x, Team[x]));
			}
			else
			{
				printf("%d\n", q.front().first);
				q.pop();
			}
		}
		printf("\n");
	}
}
