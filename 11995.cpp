#include "pch.h"
#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int main()
{
	freopen("Input.txt", "r", stdin);

	int N;
	while (scanf("%d", &N) != EOF)
	{
		bool isqueue = true, ispriorqueue = true, isstack = true;
		stack<int> mystack;
		queue<int> myqueue;
		priority_queue<int> mypriorqueue;

		for(int i = 0; i < N; i++)
		{
			int x, y; scanf("%d %d", &x, &y);

			if (x == 1)
			{
				if (isstack)
					mystack.push(y);
				if (isqueue)
					myqueue.push(y);
				if (ispriorqueue)
					mypriorqueue.push(y);
			}
			else
			{
				if (isstack)
					if (mystack.empty() || mystack.top() != y)
						isstack = false;
					else
						mystack.pop();
				if(isqueue)
					if (myqueue.empty() || myqueue.front() != y)
						isqueue = false;
					else
						myqueue.pop();
				if(ispriorqueue)
					if (mypriorqueue.empty() || mypriorqueue.top() != y)
						ispriorqueue = false;
					else
						mypriorqueue.pop();
			}
		}

		if (isstack && !isqueue && !ispriorqueue)
			printf("stack\n");
		else if (!isstack && isqueue && !ispriorqueue)
			printf("queue\n");
		else if (!isstack && !isqueue && ispriorqueue)
			printf("priority queue\n");
		else if (!isstack && !isqueue && !ispriorqueue)
			printf("impossible\n");
		else
			printf("not sure\n");
	}
}