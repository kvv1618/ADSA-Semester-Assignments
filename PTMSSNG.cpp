#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
#define FIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod   1000000007

int main()
{
    FIO;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		map<int,int>x_cord,y_cord;
		int x1,y1,ans_x,ans_y;
		for(int i=0;i<4*n-1;i++)
		{
			cin>>x1>>y1;
			x_cord[x1]++;
			y_cord[y1]++;
		}
		for(auto j=y_cord.begin();j!=y_cord.end();j++)
		{
			if(j->second%2!=0)
			{
				ans_y=j->first;
				break;
			}
		}
		for(auto j=x_cord.begin();j!=x_cord.end();j++)
		{
			if(j->second%2!=0)
			{
				ans_x=j->first;
				break;
			}
		}
		cout<<ans_x<<" "<<ans_y<<endl;
		
	}

}
