#include <iostream>
#include <stdio.h>
#include <bitset>

using namespace std;

#define mod 131071
#define ll long long int
#define mult(a, b) (((a % mod) * (b % mod)) % mod)
#define sum(a, b) (((a % mod) + (b % mod)) % mod)

ll power(int n, int e)
{
	if (e == 0) return 1;
	if (e == 1) return n;
	
	ll resp = power(n, e / 2);
	resp = mult(resp, resp);
	
	if (e % 2) resp = mult(resp, n);
	
	return resp;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	char c;
	while(scanf(" %1c", &c) != EOF)
	{
		string str = "";
		
		while(c != '#')
		{
			str += c;
			scanf(" %1c", &c);
		}
		
		int number = 0;
		for (int i = str.length() - 1, cnt = 0; i >= 0; i--, cnt++)
			if (str[i] == '1')
				number = sum(number, power(2, cnt));
						
		if (number % mod == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
