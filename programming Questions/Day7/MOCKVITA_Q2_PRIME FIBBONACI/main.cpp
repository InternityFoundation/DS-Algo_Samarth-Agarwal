#include <bits/stdc++.h>
#include<string>
using namespace std;

int isPrime(int n)
{
    for(int k=2;k<=n/2;k++)
    {
        if(n%k==0)
            return 0;
    }
    return 1;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n1,n2;
    cin>>n1>>n2;
    int i,j;
    int primes[n2+1];
    for(i=0;i<=n2;i++)
        primes[i]=1;
    primes[0]=primes[1]=0;
    for(i=2;i<=n2;i++)
    {
        if(primes[i]==1)
        {
            for(j=2;i*j<=n2;j++)
                primes[i*j]=0;
        }
    }
    vector<int> P;
    vector<int> Q;
    for(i=n1;i<=n2;i++)
        if(primes[i]==1)
            P.push_back(i);

    int ct=0;
    vector<int>::iterator m;
    vector<int>::iterator n;
    for(m=P.begin();m!=P.end();m++)
    {
        for(n=P.begin();n!=P.end();n++)
        {
            if(m==n)
                continue;
            else
            {
                ostringstream str1;
                str1 << *m;
                str1 << *n;
                string geek = str1.str();
                int c,d=0;
                int s=geek.size();
                for(c=0;c<s;c++)
                {
                    d=(d*10)+(((int)geek[c])-48);
                }
                ct++;
                if(isPrime(d))
                    Q.push_back(d);
            }
        }
    }

    sort(Q.begin(),Q.end());
    int len=0;

    for(m=Q.begin();m!=Q.end();m++)
    {
//        cout<<*m<<" ";
        if(m<Q.end() && *m==*(m+1))
            continue;
        else
            len++;
    }
    //cout<<"\n"<<ct<<"\n"<<Q.size()<<"\n"<<len;

    m=Q.begin();
    long long int a=*m;
    m=Q.end()-1;
    long long int b=*m;
    //cout<<endl<<a<<" "<<b<<" ";
    long long int sum=0;
    for(int x=1;x<=len-2;x++)
    {
        sum=a+b;
        a=b;
        b=sum;
    }
    cout<<"\n"<<sum<<"\n";
    return 0;
}
