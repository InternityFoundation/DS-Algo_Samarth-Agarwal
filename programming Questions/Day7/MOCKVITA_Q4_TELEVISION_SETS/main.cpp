#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll N;
    cin>>N;
    ll R1,R2;
    cin>>R1>>R2;
    ll rev;
    cin>>rev;
    ll i,j,k;
    ll A[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(i=N;i>=0;i--)
    {
        ll sum=0;
        ll d=0;
        for(j=1;j<=12;j++)
        {
            ll a=pow(abs(6-j),2);
            //cout<<d<<endl;
            for(k=1;k<=A[d];k++)
            {
                ll b=abs(k-15);
                ll c=a+b; //number of patients
                if(c>N)
                {
                    sum=sum+(R1*i)+(R2*(N-i));
                }
                else
                {
                    if(c>(N-i))
                    {
                        sum=sum+(R2*(N-i))+(R1*(c-N+i));
                    }
                    else
                    {
                        sum=sum+(R2*c);
                    }
                }
            }
            d++;
        }
     //   cout<<i<<" "<<sum<<"\n";
        if(sum<rev)
            break;
    }
    if(i==N)
        cout<<N;
    else
        cout<<i+1;
    return 0;
}
