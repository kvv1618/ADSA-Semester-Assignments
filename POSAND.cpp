#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
#define FIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod   1000000007
int main() {
	FIO;
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    if(n==1)
	    {
	        cout<<"1"<<endl;
	        continue;
	    }
	    if(n==3)
	    {
	        cout<<"2 3 1"<<endl;
	        continue;
	    }
	    int tmp=n;
	    while(tmp%2==0)
	    tmp/=2;
	    if(tmp==1)
	    {
	        cout<<"-1"<<endl;
	        continue;
	    }
	    
	    int p=3,pw;
	    pw=pow(2,p);
	    cout<<"2 3 1 5 4 ";
	    for(int i=6;i<=n;i++)
	    {
	        if(i+1==pw && i!=n)
				{
					cout<<i<<" "<<pw+1<<" "<<pw<<" ";
					i+=2;
					p+=1;
					pw = pow(2,p);
				}
			else
			cout<<i<<" ";
	    }
	    cout<<endl;
	}

	return 0;
}
