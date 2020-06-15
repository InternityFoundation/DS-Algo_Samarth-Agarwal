#include <bits/stdc++.h>
using namespace std;

string check(int A[],int N)
{
    unordered_map<int,int> m;
    if(A[0]!=5)
        return "NO";
    for(int i=0;i<N;i++)
    {
        if(A[i]==5)
            m[5]++;
        else if(A[i]==10)
        {
            m[10]++;
            if(m[5]>0)
                m[5]--;
            else
                return "NO";
        }
        else if(A[i]==15)
        {
            if(m[10]>0)
                m[10]--;
            else if(m[5]>1)
                m[5]=m[5]-2;
            else
                return "NO";
        }
    }
    return "YES";
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        cout<<check(A,N)<<"\n";
    }
    return 0;
}
