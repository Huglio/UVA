#include <stdio.h>
#include <queue>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

struct Pos
{
	public:
	
		int i;
		int j;
	
		int R;
		int Moves = 0;
};

int N, M;

bool Matrix[55][55];

int di[12] = {3, 2, 1,-1,-2,-3, 0, 0, 0, 0, 0, 0};
int dj[12] = {0, 0, 0, 0, 0, 0, 3, 2, 1,-1,-2,-3};

int BFS(int Starti, int Startj, int Endi, int Endj, string Rotation)
{
	Pos Start;
	Start.i = Starti;
	Start.j = Startj;
	
	if(Rotation == "south")
		Start.R = 2;
	else if(Rotation == "north")
		Start.R = 0;
	else if(Rotation == "east")
		Start.R = 1;
	else
		Start.R = 3;
		
	queue<Pos> q;
	Matrix[Starti][Startj] = true;
	
	while(!q.empty())
	{
		Pos r = q.front(); q.pop();
		
		if(r.i == Endi && r.j == Endj)
			return r.Moves;
		else
		{
			for(int k = 0; k < 12; k++)
			{
				if(r.i + di[k] < N && r.i + di[k] >= 0 && r.j + dj[k] < M && r.j + dj[k] >= 0)
				{
					int Evaluate;
					for(Evaluate = 0; Evaluate < abs(di[k] + dj[k]) && Matrix[r.i+di[k]][r.j+dj[k]]; Evaluate++);
					
					
					if(Evaluate == abs(di[k] + dj[k]))
					{
						Pos ToPush = r;
						ToPush.Moves += abs(di[k] + dj[k]);
						Matrix[r.i+di[k]][r.j+dj[k]] = true;
					}
				}
			}
		}
	}
	
}

int main()
{
	freopen("Input.txt", "r", stdin);
	
	scanf("%d %d", &N, &M);
	
	bool TempMatrix[50][50];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
		{
			int Temp;
			scanf("%d", &Temp);
			
			TempMatrix[i][j] = Temp;
		}
		
	for(int i = 0; i < N+1; i++)
		for(int j = 0; j < M+1; j++)
		{
			if(
			i - 1 >=0 
			&& i < N 
			&& j - 1 >= 0 
			&& j < M 
			&& !TempMatrix[i-1][j] 
			&& !TempMatrix[i][j-1] 
			&& !TempMatrix[i-1][j-1] 
			&& !TempMatrix[i][j])
			{
				Matrix[i][j] = false;
			}
			else
				Matrix[i][j] = true;
		}
	
	N++, M++;
	int Si, Sj, Ei, Ej; string R;
	scanf("%d %d %d %d", &Si, &Sj, &Ei, &Ej);
	cin >> R;
	
	
	printf("%d\n", BFS(Si, Sj, Ei, Ej, R));
}
