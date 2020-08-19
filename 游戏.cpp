#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int a,b,c;
int main()
{
	freopen("store.in","r",stdin);
	freopen("store.out","w",stdout);
	int T = 0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&c);
		int l = 0,r = min(a,b);
		while(l < r)
		{
			int mid = (l + r + 1) / 2;
			int A = a - mid;
			int B = b - mid;
			int C = c;
			int Jud = A + B + C;
			if(Jud < mid)
			{
				r = mid - 1;
				continue;
			}
			if(A + B >= mid / 2 &&
			   A + C >= mid / 2 &&
			   B + C >= mid / 2)
			    l = mid;
			else
				r = mid - 1;
		}
		printf("%d\n",l);
	}
}
