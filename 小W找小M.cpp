# OI
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxsize = 110;
int n;
struct star
{
	double x;
	double y;
	double z;
	double r;
}Stars[maxsize],W,M,CLE;
double dist = 0;
double cd(star fir,star sec)
{
	double X = fir.x - sec.x,
		Y = fir.y - sec.y,
		Z = fir.z - sec.z;
	return (double)sqrt(X * X + Y * Y + Z * Z);
}
double dp[maxsize][maxsize];
void CLS()
{
	memset(Stars,0,sizeof(Stars));
	memset(dp,0x7f,sizeof(dp));
	W = CLE;
	M = CLE;
}
void readin()
{
	for(int i = 1;i <= n;i++)
		cin>>Stars[i].x>>Stars[i].y>>Stars[i].z>>Stars[i].r;
	cin>>W.x>>W.y>>W.z;
	cin>>M.x>>M.y>>M.z;
	return ;
}
int main()
{
	freopen("warp.in","r",stdin);
	freopen("warp.out","w",stdout);
	while(1)
	{
		scanf("%d",&n);
		if(n == -1)
			break;
		CLS();
		readin();
		dist = cd(W,M);
		dp[0][n + 1] = dist;
		dp[0][0] = 0;
		dp[n + 1][n + 1] = 0;
		for(int i = 1;i <= n;i++)
		{
			dp[0][i] = max(cd(W,Stars[i]) - Stars[i].r,0.0);
			dp[i][n + 1] = max(0.0,cd(Stars[i],M) - Stars[i].r);
		}
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
			{
				dp[i][j] = max(0.0,cd(Stars[i],Stars[j]) - Stars[i].r - Stars[j].r);
				if(i == j)
					dp[i][j] = 0;
				dp[j][i] = dp[i][j];
			}
		for(int k = 1;k <= n;k++)
			for(int i = 0;i <= n + 1;i++)
				for(int j = 0;j <= n + 1;j++)
					dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
		double ans = dp[0][n + 1];
		int Tim = (int)((ans / 0.1) + 0.5);
		printf("%d\n",Tim);
	}
	return 0;
}
