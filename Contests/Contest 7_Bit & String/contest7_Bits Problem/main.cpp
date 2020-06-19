#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<int> V;
    V.push_back(0);
    for(int i=1;i<=N;i++)
    {
        V.push_back(V[i/2]+(i & 1));
    }
    for(int i=0;i<V.size();i++)
    {
        cout<<V[i]<<" ";
    }
//    for(int i=0;i<=N;i++)
//    {
//        bitset<32> b1(i);
//        cout<<b1.count()<<" ";
//    }

    return 0;
}
