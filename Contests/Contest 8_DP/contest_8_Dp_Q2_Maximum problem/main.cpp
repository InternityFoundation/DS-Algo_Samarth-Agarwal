#include<bits/stdc++.h>
using namespace std;

int maxProduct(int A[],int n)
{
    int max_ending=1;
    int min_ending=1;

    int max_so_far=1;
    int flag=0;

    for(int i=0;i<n;i++)
    {
        if(A[i]>0)
        {
            max_ending=max_ending*A[i];
            min_ending=min(1,min_ending*A[i]);
            flag=1;
        }
        else if(A[i]==0)
        {
            max_ending=1;
            min_ending=1;
        }
        else
        {
            int t=max_ending;
            max_ending=max(min_ending*A[i],1);
            min_ending=t*A[i];
        }

        if(max_so_far<max_ending)
            max_so_far=max_ending;
    }

    if(flag==0 && max_so_far==1)
        return 0;
    return max_so_far;
}



int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    if(n==0)
    {
        cout<<"0";
    }
    else if(n==1)
    {
        cout<<A[0];
    }
    else
    {
        cout<<maxProduct(A,n);
    }
    return 0;
}
