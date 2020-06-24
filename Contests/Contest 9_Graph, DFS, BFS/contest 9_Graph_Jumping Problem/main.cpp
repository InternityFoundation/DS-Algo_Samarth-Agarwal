#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;
public:
    Graph(int V)
    {
        this->V=V;
        l=new list<int> [V];
    }

    void addEdge(int x,int y)
    {
        l[x].push_back(y);
    }

    string dfs(int start)
    {
        map<int,bool> visited;
        /*for(auto p:l)
        {
            int node=p.first;
            visited[node]=false;
        }*/
        return dfs_helper(start,visited);
    }

    int f=0;
    string dfs_helper(int start,map<int,bool> &visited)
    {
        //cout<<start<<" ";
        visited[start]=true;
        for(int nbr:l[start])
        {
            //cout<<nbr<<" ";
            if(nbr==V)
            {
                f=1;
                break;
            }

            if(!visited[nbr])
            {
                dfs_helper(nbr,visited);
            }
        }
        if(f==0)
            return "false";
        else
            return "true";
    }

};
int main()
{
    int N;
    cin>>N;
    Graph g(N);
    for(int i=0;i<N;i++)
    {
        int p;
        cin>>p;
        if(p!=0)
        {
            if(i-p>=0)
                g.addEdge(i,i-p);
            if(i+p<N)
                g.addEdge(i,i+p);
        }
        else
        {
            g.addEdge(i,N);
        }
    }
    int start;
    cin>>start;
    cout<<g.dfs(start);
    return 0;
}
