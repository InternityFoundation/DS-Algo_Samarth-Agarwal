#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& V,int i,int j,int m,int n)
{
    if(i<0 || j<0 || i>=m || j>=n || V[i][j]!=0)
        return;
    V[i][j]=2;
    dfs(V,i-1,j,m,n);
    dfs(V,i+1,j,m,n);
    dfs(V,i,j-1,m,n);
    dfs(V,i,j+1,m,n);
}


void solve(vector<vector<int>>& V)
{
    int m=V.size();
    if(m==0)
        return;
    int n=V[0].size();

    for(int i=0;i<m;i++)
    {
        if(V[i][0]==0)
             dfs(V,i,0,m,n);
        if(V[i][n-1]==0)
             dfs(V,i,n-1,m,n);
    }

    for(int j=0; j<n; j++)
    {
        if(V[0][j]==0)
             dfs(V,0,j,m,n);
        if(V[m-1][j]==0)
             dfs(V,m-1,j,m,n);
    }

    for(int i=0;i<m;i++)
    {
         for(int j=0;j<n;j++)
         {
             if(V[i][j]==0)
                 V[i][j]=1;
             if(V[i][j]==2)
                 V[i][j]=0;
         }
    }
}


int main()
{
    int m,n;
    cin>>m>>n;
    int p;
    vector<vector<int>> V;
    for(int i=0;i<m;i++)
    {
        vector<int> S;
        for(int j=0;j<n;j++)
        {
            cin>>p;
            S.push_back(p);
        }
        V.push_back(S);
    }
    solve(V);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<V[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
