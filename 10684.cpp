#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int V[10010];
	int n;

	while(scanf("%d", &n), n)
	{
		for(int i=0; i < n; i++)
			scanf("%d", &V[i]);
			
		int soma = 0;
		int ans = 0;
		
		for(int i = 0; i < n; i++)
		{
			soma += V[i];

			ans = max(ans, soma);
			
			if(soma <= 0)
				soma = 0;
				
		}
		
		if(ans)
			printf("The maximum winning streak is %d.\n", ans);
		else
			printf("Losing streak.\n");
	}
}
