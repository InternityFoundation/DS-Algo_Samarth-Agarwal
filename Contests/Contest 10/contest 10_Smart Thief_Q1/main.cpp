#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int A[N];
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    int dp[N+1];
    dp[0]=0;
    dp[1]=A[0];
    for(int i=1;i<N;i++)
    {
        dp[i+1]=max(dp[i],dp[i-1]+A[i]);
    }
    cout<<dp[N];
    return 0;
}
