#define ll long long

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin>>T;
    while(T--)
    {
        ll N,Q;
        cin>>N>>Q;
        string S;
        cin>>S;
        unordered_map<char,ll> m;
        for(ll j=0;j<N;j++)
        {
            m[S[j]]++;
        }
        for(ll i=0;i<Q;i++)
        {
            ll C;
            cin>>C;
            if(C>=N)
            {
                cout<<0<<endl;
            }
            else
            {
                ll ct=0;
                unordered_map<char,ll>::iterator p=m.begin();
                while(p!=m.end())
                {
                    if(p->second>C)
                        ct+=(p->second-C);
                    p++;
                }
                cout<<ct<<endl;
            }
        }
    }

    return 0;
}

