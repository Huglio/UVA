#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int main()
{
	int TC; scanf("%d", &TC);
	
	int tc = 1;
	while(TC--)
	{
		string str; cin >> str;
		
		int rest[3]; memset(rest, 0, sizeof(rest));
		
		int allrest = 0;
		for (int i = 0; i < (int)str.length(); i++)
		{
			rest[((int)str[i] - '0') % 3]++;
			allrest = ((allrest % 3) + (((int)str[i] - '0') % 3)) % 3;
		}
		
		printf("Case %d: ", tc++);
		
		if(allrest && !rest[allrest])
			printf("T\n");
		else if(allrest && rest[allrest])
		{			
			if(rest[0] % 2)
				printf("T\n");
			else
				printf("S\n");
		}
		else
		{
			if(rest[0] % 2)
				printf("S\n");
			else
				printf("T\n");
		}
	}
}
