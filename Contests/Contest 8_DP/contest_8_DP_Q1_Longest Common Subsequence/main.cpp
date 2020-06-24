#include<bits/stdc++.h>
using namespace std;

int subString(string s1,string s2)
{
    int m=s1.size();
    int n=s2.size();
    if(m==0 || n==0)
        return 0;
    int A[m+1][n+1];

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                A[i][j]=0;
            else  if(s1[i-1]==s2[j-1])
                A[i][j]=A[i-1][j-1]+1;
            else
                A[i][j]=max(A[i-1][j],A[i][j-1]);
        }
    }
    return A[m][n];
}



int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    cout<<subString(s1,s2);
    return 0;
}
