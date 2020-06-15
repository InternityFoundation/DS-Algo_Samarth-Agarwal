#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,K;
        cin>>N>>K;
        int sum=0,p;
        for(int i=0;i<N;i++)
        {
            cin>>p;
            if(p>K)
                sum+=(p-K);
        }
        cout<<sum<<endl;
    }
    return 0;
}
