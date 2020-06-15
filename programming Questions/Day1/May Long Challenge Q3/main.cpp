#define ll long long
#include <bits/stdc++.h>

using namespace std;

void possible(vector<ll> A,vector<ll> B,ll K)
{
    vector<ll> C;
    ll i,j,ct=0,k=0;
    for(i=0;i<A.size();i++)
    {
        if(A[i]!=B[i])
        {
            ct++;
            C.push_back(i+1);
        }
    }
    if((K*3)>=ct)
    {
        cout<<(ct/3)<<endl;
        for(i=0;i<(ct/3);i++)
        {
            for(j=k;j<k+3;j++)
                cout<<C[j]<<" ";
            k=k+3;
            cout<<"\n";
        }
    }
    else
        cout<<-1<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;
    cin>>T;
    while(T--)
    {
        vector<ll> A;
        vector<ll> B;
        ll N,K,i,j;
        cin>>N>>K;
        for(i=0;i<N;i++)
        {
            cin>>j;
            A.push_back(j);
            B.push_back(j);
        }
        sort(A.begin(),A.end());
        possible(A,B,K);
    }
    return 0;
}
