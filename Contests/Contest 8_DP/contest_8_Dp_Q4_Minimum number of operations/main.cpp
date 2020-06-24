#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;

    int m=s1.size();
    int n=s2.size();
    int dp[m+1][n+1];

    if(m==0)
        cout<<n;
    else if(n==0)
        cout<<m;
    else
    {
        for(int i=0;i<m;i++)
            dp[i][0]=i;
        for(int i=0;i<n;i++)
            dp[0][i]=i;

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                {
                    int a=min(dp[i-1][j],dp[i][j-1]);
                    dp[i][j]=1+min(a,dp[i-1][j-1]);
                }
            }
        }
        cout<<dp[m][n];
    }
    return 0;
}
