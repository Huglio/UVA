#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int bignumber[5000];
string resp[5000];

int main()
{
	resp[0] = "1";
	
	memset(bignumber, 0, sizeof(bignumber));
	
	bignumber[0] = 1;
	
	int digits = 1;
	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 0; j < digits; j++)
			bignumber[j] *= i;
		int lastdigit = digits;
		for (int j = 0; j < digits; j++)
		{
			if(j + 1 == lastdigit)
				digits += log10(bignumber[j]);
			
			bignumber[j + 1] += bignumber[j] / 10;
			bignumber[j] = bignumber[j] % 10;
		}
		
		string str = "";
		
		for (int i = digits - 1; i >= 0; i--)
		{
			str += ('0' + bignumber[i]);
		}
			
		resp[i] = str;
	}
	
	int n;
	while(scanf("%d", &n) != EOF)
	{
		printf("%d!\n", n);
		cout << resp[n] << endl;
		cout << resp[n].length() << endl;
	}
}
