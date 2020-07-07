#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int A[N],B[N];
    for(int i=0;i<N;i++)
        cin>>A[i];

    for(int i=0;i<N;i++)
        B[i]=0;

    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(A[j]<A[i])
                B[i]++;
        }
    }

    for(int i=0;i<N;i++)
        cout<<B[i]<<" ";

    return 0;
}
