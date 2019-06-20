#include "pch.h"
#include <stdio.h>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int main()
{
	int k; scanf("%d", &k);
	while (k--)
	{
		int n, m; scanf("%d %d", &n, &m);

		set<int> Nums;

		map<int, int> A;
		map<int, int> B;

		for (int i = 0; i < n; i++)
		{
			int x; scanf("%d", &x);
			A[x]++; Nums.insert(x);
		}
		for (int i = 0; i < m; i++)
		{
			int x; scanf("%d", &x);
			B[x]++; Nums.insert(x);
		}

		int contador = 0;
		for (set<int>::iterator it = Nums.begin(); it != Nums.end(); it++)
			contador += abs(A[*it] - B[*it]);

		printf("%d\n", contador);
	}
}