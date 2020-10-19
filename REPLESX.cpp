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
	    int n,x,p,k;
		cin>>n>>x>>p>>k;
		int arr[n],tmp[n],ans=0;
		for(int i=0;i<n;i++)
		{
		    cin>>arr[i];
		    tmp[i]=arr[i];
		}
		sort(arr,arr+n);
		if(arr[p-1]==x)
		{
		    cout<<"0"<<endl;
		    continue;
		}
		if(n>3000)
		{
		    if(k==p)
		    {
		        ans=0;
    			if(arr[p-1]>x)
    			{
    				for(int i=0;i<p;i++)
    				{
    					if(arr[i]>x)
    					ans++;
    				}
    			}
    			else
    			{
    				for(int i=p-1;i<n;i++)
    				{
    					if(arr[i]<x)
    					ans++;
    				}
    			}
    			cout<<ans<<endl;
    			continue;
		    }
		    if(k<p)
		    {
		        int chk=0;
		        for(int i=0;i<n;i++)
		        if(arr[i]>x)
		        chk++;
		        if(p==n)
		        {
		            if(x>arr[n-1] && k<n)
                    {
                        cout<<"1"<<endl;
                        continue;
                    }
                    else
                    {
                        cout<<"-1"<<endl;
                        continue;
                    }
		        }
		        if(chk>=n-p)
		        {
		            cout<<"-1"<<endl;
		            continue;
		        }
		        ans=0;
		        for(int i=p-1;i<n;i++)
		        if(arr[i]<x)
		        ans++;
		        cout<<ans<<endl;
		    }
		    if(k>p)
		    {
		        int chk=0;
    		    for(int i=0;i<n;i++)
    			if(arr[i]<x)
    			chk++;
    			if(p==0)
                {
                    if(x<arr[0] && k>0)
                    {
                        cout<<"1"<<endl;
                        continue;
                    }
                    else
                    {
                        cout<<"-1"<<endl;
                        continue;
                    }
                }
    			if(chk>=p)
    			{
    				cout<<"-1"<<endl;
    				continue;
    			}
    			ans=0;
    			for(int i=0;i<=p-1;i++)
    			{
    				if(arr[i]>x)
    				ans++;
    			}
    			cout<<ans<<endl;
		    }
		}
		else
		{
		    ans=0;
		    while(1)
		    {
		        arr[k-1]=x;
		        ans++;
		        sort(arr,arr+n);
		        if(arr[p-1]==x)
		        {
		            cout<<ans<<endl;
		            break;
		        }
		        int chk=0;
		        for(int i=0;i<n;i++)
		        {
		            if(tmp[i]==arr[i])
		            chk++;
		            
		            tmp[i]=arr[i];
		        }
		        if(chk==n)
		        {
		            cout<<"-1"<<endl;
		            break;
		        }
		    }
		    continue;
		}
		
	    
	}

	return 0;
}
