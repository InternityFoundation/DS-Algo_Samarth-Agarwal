#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll check(ll TS)
{
    if(TS<=1LL)
        return 0;
    if(TS%2LL==1LL)
        return ((TS-1LL)/2LL);
    else
    {
        ll n=TS,ct=0LL;
        while(n%2LL!=1LL)
        {
            n=(ll)n/2LL;
            ct++;
        }
        if(n==1LL)
            return 0;
        ll q=powl(2LL,ct);
        ll temp=q*2LL;
         return (TS/temp);
    }
}

int main()
{
    ll T;
    cin>>T;
    while(T--)
    {
        ll TS;
        cin>>TS;
        cout<<check(TS)<<endl;
    }
    return 0;
}
