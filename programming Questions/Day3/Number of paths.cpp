#include <bits/stdc++.h>
using namespace std;

int calc(int M,int N)
{
    if(M==1 || N==1)
        return 1;
    return calc(M-1,N)+calc(M,N-1);
}

int main() 
{
    int T;
    cin>>T;
    while(T--)
    {
        int M,N;
        cin>>M>>N;
        cout<<calc(M,N)<<endl;
    }
	//code
	return 0;
}