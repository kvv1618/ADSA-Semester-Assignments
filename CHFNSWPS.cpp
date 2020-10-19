#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
#define FIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod   1000000007

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a_arr,b_arr;
        int i=0,mn=mod,temp;
        for(i=0;i<n;i++)
        {
            cin>>temp;
            a_arr.push_back(temp);
        }
        for(i=0;i<n;i++)
        {
            cin>>temp;
            b_arr.push_back(temp);
        }
        map<int,int>total,a_map,b_map,swapable;
        sort(a_arr.begin(),a_arr.end());
        sort(b_arr.begin(),b_arr.end());
        for(i=0;i<n;i++)
        {
            if(a_arr[i]<mn)
            mn=a_arr[i];              //For min swaps

            if(b_arr[i]<mn)
            mn=b_arr[i];

            total[a_arr[i]]++;   //Includes array a elemets with count
            total[b_arr[i]]++;   //Includes array b elemets with count

            a_map[a_arr[i]]++;   //Seperate map for array a

            b_map[b_arr[i]]++;   //Seperate map for array b
        }
        ll res=0,tot_swa=0,req_swa=0;
        for(i=0;i<n;i++)
        {
            if(a_map[a_arr[i]]-b_map[a_arr[i]]!=0)
            swapable[a_arr[i]]=abs(a_map[a_arr[i]]-b_map[a_arr[i]])/2;
            if(a_map[b_arr[i]]-b_map[b_arr[i]]!=0)
            swapable[b_arr[i]]=abs(a_map[b_arr[i]]-b_map[b_arr[i]])/2;
        }
        for(auto j=swapable.begin();j!=swapable.end();j++)
        {
            tot_swa+=j->second;
        }
       // cout<<tot_swa<<endl;
        int odd_check=-1;
        for(auto j=total.begin();j!=total.end();j++)
        {
            if(j->second%2!=0)
            {
                odd_check=1;
                break;
            }
        }
        if(odd_check==1)
        {
            cout<<"-1"<<endl;
            continue;
        }
        for(auto j=swapable.begin();j!=swapable.end();j++)
        {
            if(req_swa>=tot_swa/2)
            break;
            if(req_swa+j->second>tot_swa/2)
            {
                if(mn*2>j->first)
                for(i=0;i<tot_swa/2-req_swa;i++)
                res+=j->first;
                else
                for(i=0;i<tot_swa/2-req_swa;i++)
                res+=mn*2;

                req_swa+=tot_swa/2-req_swa;
            }
            else
            {
                if(mn*2<j->first)
                for(i=0;i<j->second;i++)
                res+=mn*2;
                else
                for(i=0;i<j->second;i++)
                res+=j->first;

                req_swa+=j->second;
            }   
        }
        cout<<res<<endl;

        
        

    }
}
