#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll T;
    cin>>T;
    while(T--)
    {
        ll N;
        cin>>N;
        ll A[N][N];
        ll k=1,dir=0,T=0,B=N-1,L=0,R=N-1,i,j;
        while(T<=B && L<=B)
        {
            if(dir==0)
            {
                for(i=L;i<=R;i++)
                {
                    A[T][i]=k;
                    k++;
                }
                T++;
            }
            else if(dir==1)
            {
                for(i=T;i<=B;i++)
                {
                    A[i][R]=k;
                    k++;
                }
                R--;
            }
            else if(dir==2)
            {
                for(i=R;i>=L;i--)
                {
                    A[B][i]=k;
                    k++;
                }
                B--;
            }
            else if(dir==3)
            {
                for(i=B;i>=T;i--)
                {
                    A[i][L]=k;
                    k++;
                }
                L++;
            }
            dir++;
            dir=dir%4;
        }
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                cout<<A[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}
