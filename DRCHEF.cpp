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
	    int n,x,i,temp;
	    cin>>n>>x;
	    vector<int>ppl,org;
	    ll res=0;
	    for(i=0;i<n;i++)
	    {
	        cin>>temp;
	        ppl.push_back(temp);
	        org.push_back(temp);
	    }
	    sort(ppl.begin(),ppl.end());
	    sort(org.begin(),org.end());
	    for(i=0;i<n;i++)
	    {
	        if(2*ppl[i]<x)
	        {
	            res++;
	            continue;
	        }
	        while(ppl[i]>0)
	        {
	            if(x<ppl[i])
	            {
	                ppl[n-1]-=x;
	                x+=x;
	                ppl[n-1]*=2;
	                if(ppl[n-1]>org[n-1])
	                ppl[n-1]=org[n-1];
	                res++;
	            }
	            else
	            {
	                x=ppl[i]*2;
	                ppl[i]=0;
	                res++;
	                break;
	            }
	        }
	        
	    }
	    cout<<res<<endl;
	}

	return 0;
}
