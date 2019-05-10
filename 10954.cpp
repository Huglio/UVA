#include <stdio.h>
#include <queue>

using namespace std;

class mycomparison
{
	public:
	mycomparison(){};

	bool operator() (const int &lhs, const int &rhs) const
	{
		return lhs > rhs;
	}
};

int main()
{
	int N;
	while(scanf("%d", &N) && N)
	{
		priority_queue<int, vector<int>, mycomparison> q;
		
		for(int i = 0; i < N; i++)
		{
			int x; scanf("%d", &x);
			q.push(x);
		}
		
		int Sum = 0;
		while(q.size() > 1)
		{
			int x = q.top(); q.pop();
			int y = q.top(); q.pop();
			
			Sum += x + y;
			q.push(x + y);
		}
		
		printf("%d\n", Sum);
	}
}
