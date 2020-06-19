#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll m,n,result;
    cin>>m>>n;
    if(m==0)
        cout<<0;
    else if(m==n)
        cout<<m;
    else
    {
        result=m;
        for(ll i=m+1;i<=n;i++)
        {
            result&=i;
            //cout<<result<<" ";
        }
        cout<<result;
    }
    return 0;
}
