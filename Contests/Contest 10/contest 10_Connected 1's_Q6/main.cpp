#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &A,int i,int j)
{
    if(i>A.size()-1 || i<0 || j<0 || j>A[i].size()-1)
        return;
    if(A[i][j]==2 || A[i][j]==0)
        return;
    A[i][j]=2;
    dfs(A,i,j+1);
    dfs(A,i,j-1);
    dfs(A,i+1,j);
    dfs(A,i-1,j);
}


int main()
{
    int r,c;
    cin>>r>>c;
    vector<vector<int>> A;
    int p;
    for(int i=0;i<r;i++)
    {
        vector<int> B;
        for(int j=0;j<c;j++)
        {
            cin>>p;
            B.push_back(p);
        }
        A.push_back(B);
    }

    int ct=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(A[i][j]==1)
            {
                ct++;
                dfs(A,i,j);
            }
        }
    }

    cout<<ct;
    return 0;
}
