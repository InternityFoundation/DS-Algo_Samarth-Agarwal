#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int i=0;
        while(pow(2,i)<=N)
            i++;
        cout<<i<<endl;
    }
    return 0;
}
