#include <bits/stdc++.h>
using namespace std;

void dfs(int index,vector<int>& vis,vector<vector<int>> A)
{
    vis[index]=1;
    for(int i=0;i<A[index].size();i++)
    {
        if(!vis[i] && A[index][i]==1)
            dfs(i,vis,A);
    }
}

int countGroups(vector<vector<int>> A)
{
    vector<int> vis(A.size(),0);
    int ct=0;
    for(int i=0;i<A.size();i++)
    {
        if(!vis[i])
        {
            ct++;
            dfs(i,vis,A);
        }
    }
    return ct;
}


int main()
{
    int N;
    cin>>N;
    int p;
    vector<vector<int>> A;
    for(int i=0;i<N;i++)
    {
        vector<int> S;
        for(int j=0;j<N;j++)
        {
            cin>>p;
            S.push_back(p);
        }
        A.push_back(S);
    }
    cout<<countGroups(A);
    return 0;
}
