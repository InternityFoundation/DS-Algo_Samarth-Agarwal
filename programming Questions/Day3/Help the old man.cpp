#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int s,int a,int d,int n,int m,int &from,int &to,int &move)
{
    if(n==1)
    {
        move++;
        if(move==m)
        {
            from=s;
            to=d;
        }
        return;
    }
    
    towerOfHanoi(s,d,a,n-1,m,from,to,move);
    move++;
    if(move==m)
    {
        from=s;
        to=d;
        return;
    }
    towerOfHanoi(a,s,d,n-1,m,from,to,move);
}

int main() 
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,s=1,a=2,d=3,from,to,move=0;
        cin>>n>>m;
        towerOfHanoi(s,a,d,n,m,from,to,move);
        cout<<from<<" "<<to<<endl;
    }
	//code
	return 0;
}