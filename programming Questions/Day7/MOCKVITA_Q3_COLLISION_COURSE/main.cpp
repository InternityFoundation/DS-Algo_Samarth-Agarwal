#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll fact(ll n)
{
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}

ll comb(ll n)
{
    return fact(n)/(fact(2)*fact(n-2));
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    unordered_map<double,ll> m;
    double i;
    ll x,y,s;
    for(i=0;i<n;i++)
    {
        cin>>x>>y>>s;
        double time=(double)((sqrt((x*x)+(y*y))))/(double)(s);
        m[time]++;
    }
    unordered_map<double,ll>::iterator ip=m.begin();
    ll col=0;
    while(ip!=m.end())
    {
      //  cout<<ip->first<<" "<<ip->second<<"\n";
        if(ip->second>1)
            col+=comb(ip->second);
    //    cout<<ip->second<<" "<<col<<" ";
        ip++;
    }
    //cout<<endl;
    cout<<col;
    return 0;
}
