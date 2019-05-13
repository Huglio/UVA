#include <stdio.h>
#include <queue>
#include <string>
#include <iostream>

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
	
	bool Done = false;
	while(!q.empty())
	{
		Pos r = q.front(); q.pop();
		
		if(r.i == Endi && r.j == Endj)
			return r.Moves;
		else
		{
			if(i + 3 < N && !Matrix[i+3][j] && !Matrix[i+2][j] && !Matrix[i+1][j])
			if(j + 3 < M && !Matrix[i][j+3] && !Matrix[i][j+2] && !Matrix[i][j+1])
			if(i + 2 < N && !Matrix[i+2][j] && !Matrix[i+1][j])
			if(j + 2 < M && !Matrix[i][j+2] && !Matrix[i][j+1])
			if(i + 1 < N && !Matrix[i+1][j])
			if(j + 1 < M && !Matrix[i][j+1])
			if(i - 1 >= 0 && !Matrix[i-1][j])
			if(j - 1 >= 0 && !Matrix[i][j-1])
			if(i - 2 >= 0 && !Matrix[i-2][j] && !Matrix[i-1][j])
			if(j - 2 >= 0 && !Matrix[i][j-2] && !Matrix[i][j-1])
			if(i - 3 >= 0 && !Matrix[i-3][j] && !Matrix[i-2][j] && !Matrix[i-1][j])
			if(j - 3 >= 0 && !Matrix[i][j-3] && !Matrix[i][j-2] && !Matrix[i][j-1])
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

	int Si, Sj, Ei, Ej; string R;
	scanf("%d %d %d %d", &Si, &Sj, &Ei, &Ej);
	cin >> R;
	
	
	printf("%d\n", BFS(Si, Sj, Ei, Ej, R));
}
