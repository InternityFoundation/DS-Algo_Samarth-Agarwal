#include <bits/stdc++.h>
using namespace std;

int main()
{
    long T,N;
    cin>>T>>N;
    long coins[T];
    for(long i=0;i<T;i++)
    {
        cin>>coins[i];
    }
    vector<long> dp(N+1,0);

    for(long i=1;i<=N;i++)
    {
        dp[i]=INT_MAX;
        for(long j=0;j<T;j++)
        {
            if(i-coins[j]>=0)
            {
                long subprob=dp[i-coins[j]];
                dp[i]=min(dp[i],subprob+1);
            }
        }
    }
    cout<<dp[N];
    return 0;
}
