#include<bits/stdc++.h>
using namespace std;

int decode(string s)
{
    int ways_N,ways_NP1;
    int lastIndex=s.size()-1;

    if(s.size()==0)
        return 0;

    ways_NP1=1;
    ways_N=s[lastIndex]=='0'?0:1;
    lastIndex--;

    while(lastIndex>=0)
    {
        int tmp;

        bool two_Ways=s[lastIndex]=='1' || (s[lastIndex]=='2' && s[lastIndex+1]<='6');

        if(s[lastIndex]=='0')
            tmp=0;
        else if(two_Ways)
            tmp=ways_N+ways_NP1;
        else
            tmp=ways_N;

        ways_NP1=ways_N;
        ways_N=tmp;
        lastIndex--;
    }
    return ways_N;
}



int main()
{
    string s;
    cin>>s;
    cout<<decode(s);
    return 0;
}
