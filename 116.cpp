#include <iostream>
#include <algorithm>

using namespace std;

#define inf 10000000
#define up matrix[(i - 1 + n) % n][j + 1]
#define middle matrix[i][j + 1]
#define down matrix[(i + 1) % n][j + 1]
#define ii pair<int, int>

int main()
{
	freopen("in.txt", "r", stdin);
	
	int n, m;
	int matrix[20][110];
	int parent[20][110];
	
	while(scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf(" %d", &matrix[i][j]);
	
		for (int j = m - 2; j >= 0; j--)
			for (int i = 0; i < n; i++)
			{
				ii OPS[3] = {ii(up, (i - 1 + n) % n), ii(middle, i), ii(down, (i + 1) % n)};
				
				sort(OPS, OPS + 3);
				
				matrix[i][j] += OPS[0].first;
				parent[i][j] = OPS[0].second;
			}
			
		int bestid = 0;
		for(int i = 1; i < n; i++)
			bestid = matrix[bestid][0] <= matrix[i][0] ? bestid : i;
		
		int resp = matrix[bestid][0];
		
		printf("%d", bestid + 1);
		for(int j = 0; j < m - 1; j++)
		{
			bestid = parent[bestid][j];
			printf(" %d", bestid + 1);
		}
		printf("\n");
		printf("%d\n", resp);
	}
}
