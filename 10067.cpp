#include "pch.h"
#include <stdio.h>
#include <set>
#include <queue>

using namespace std;

class Wheel
{
public:
	int Num[4];


	void Add(int ToAdd, int index)
	{
		Num[index] += ToAdd;

		if (Num[index] > 9)
			Num[index] = 0;
		else if (Num[index] < 0)
			Num[index] = 9;
	}

	bool operator < (const Wheel a) const
	{
		int x = Num[3] + (Num[2] * 10) + (Num[1] * 100) + (Num[0] * 1000);
		int y = a.Num[3] + (a.Num[2] * 10) + (a.Num[1] * 100) + (a.Num[0] * 1000);

		return x > y;
	}

	bool operator == (const Wheel a) const
	{
		return a.Num[0] == Num[0] && a.Num[1] == Num[1] && a.Num[2] == Num[2] && a.Num[3] == Num[3];
	}

};

set<Wheel> Check;

int di[8] = { 0, 0, 1, 1, 2, 2, 3, 3 };
int dj[8] = { 1,-1, 1,-1, 1,-1, 1,-1 };

int BFS(Wheel Start, Wheel End)
{
	queue<Wheel> q;
	q.push(Start);
	Check.insert(Start);

	int Moves = 0;
	int Nodes_to_next = 0;
	int Nodes_left = 0;

	bool Done = false;
	while (!q.empty() && !Done)
	{
		Wheel r = q.front(); q.pop();

		if (r == End)
			Done = true;
		else
		{
			for (int i = 0; i < 8; i++)
			{
				Wheel Comp = r;
				Comp.Add(dj[i], di[i]);

				if (Check.find(Comp) == Check.end())
				{
					Check.insert(Comp);
					q.push(Comp);
					Nodes_to_next++;
				}
			}

			Nodes_left--;
			if (Nodes_left <= 0)
			{
				Moves++;
				Nodes_left = Nodes_to_next;
				Nodes_to_next = 0;
			}
		}
	}

	if (Done)
		return Moves;
	return -1;
}

int main()
{
	freopen("Input.txt", "r", stdin);

	int N; scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		Check.clear();
		Wheel Start, End;
		for (int j = 0; j < 4; j++)
			scanf("%d", &Start.Num[j]);
		for (int j = 0; j < 4; j++)
			scanf("%d", &End.Num[j]);

		int Proib; scanf("%d", &Proib);

		for (int j = 0; j < Proib; j++)
		{
			Wheel P;
			for (int k = 0; k < 4; k++)
				scanf("%d", &P.Num[k]);
			Check.insert(P);
		}

		printf("%d\n", BFS(Start, End));
	}
}