#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r,c;
    cin>>r;
    cin>>c;
    int A[r][c],S[r][c];
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>A[i][j];
        }
    }

    for(i=0;i<r;i++)
        S[i][0]=A[i][0];
    for(i=0;i<c;i++)
        S[0][i]=A[0][i];

    for(i=1;i<r;i++)
    {
        for(j=1;j<c;j++)
        {
            if(A[i][j]==1)
                S[i][j]=min(S[i-1][j-1],min(S[i-1][j],S[i][j-1]))+1;
            else
                S[i][j]=0;
        }
    }
    int maxi=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(S[i][j]>maxi)
                maxi=S[i][j];
        }
    }
    cout<<maxi*maxi;
    return 0;
}
