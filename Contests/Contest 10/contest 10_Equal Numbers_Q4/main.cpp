#include <iostream>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int A[N];
    for(int i=0;i<N;i++)
        cin>>A[i];

    int sum=0,maxi=-1;
    for(int i=0;i<N-1;i++)
    {
        if(A[i]==0)
            sum=-1;
        else
            sum=1;
        for(int j=i+1;j<N;j++)
        {
            if(A[j]==0)
                sum+=-1;
            else
                sum+=1;

            if(sum==0 && j-i+1>maxi)
                maxi=j-i+1;
        }
    }
    cout<<maxi;
    return 0;
}
