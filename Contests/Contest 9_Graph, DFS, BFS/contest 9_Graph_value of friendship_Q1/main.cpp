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

    string check()
    {
        map<int,int> m;
        map<int,int> n;
        int f;
        for(int i=0;i<V;i++)
        {
            if(m.find(i)==m.end() && n.find(i)==n.end())
            {
                m[i]++;
                f=2;
            }
            else if(m.find(i)==m.end())
            {
                f=1;
            }
            else
            {
                f=2;
            }
            for(int nbr:l[i])
            {
                if(f==1)
                {
                    if(m.find(nbr)==m.end())
                        m[nbr]++;
                }
                else
                {
                    if(n.find(nbr)==n.end())
                        n[nbr]++;
                }
            }
        }

        for(auto p:m)
        {
            if(n.find(p.first)!=n.end())
                return "no";
        }
        return "yes";
    }
};


int main()
{
    int N;
    cin>>N;
    int K;
    cin>>K;
    Graph g(N);
    for(int i=0;i<K;i++)
    {
        int a,b;
        cin>>a>>b;
        g.addEdge(a,b);
    }
    cout<<g.check();
    return 0;
}
