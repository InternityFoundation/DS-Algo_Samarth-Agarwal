#include <bits/stdc++.h>
using namespace std;

string getNext(string p)
{
    string res;
    int count=1,i=1;
    for(;i<p.size();i++)
    {
        if(p[i-1]!=p[i])
        {
            ostringstream str1;
            str1<<count;
            string c=str1.str();
            res+=c+p[i-1];
            count=1;
        }
        else
            count++;
    }
    //res+=to_string(count)+p[i-1];
    ostringstream str1;
    str1<<count;
    string c=str1.str();
    res+=c+p[i-1];
    return res;
}

int main()
{
    int N;
    cin>>N;
    string res="1";
    while(--N)
        res=getNext(res);
    cout<<res;
    return 0;
}
