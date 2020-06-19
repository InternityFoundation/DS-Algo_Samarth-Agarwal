#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int k;
    cin>>k;
    unordered_map<string,int> m;
    int n=str.size()-k;

    for(int i=0;i<=n;i++)
    {
        string s=str.substr(i,k);
        m[s]++;
    }
    if(m.size()==pow(2,k))
        cout<<"true";
    else
        cout<<"false";
}
