#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int A[N];
    for(int i=0;i<N;i++)
        cin>>A[i];
    sort(A,A+N);
    if(A[0]!=N)
        cout<<"0";
    else
    {
        int ct=N-1,f=0,sum=A[0];
        for(int i=1;i<N;i++)
        {
            if(A[i]!=(sum+ct))
            {
                f=1;
                break;
            }
            sum+=A[i];
            ct--;
        }
        if(f==1)
            cout<<"0";
        else
            cout<<"1";
    }

    return 0;
}
