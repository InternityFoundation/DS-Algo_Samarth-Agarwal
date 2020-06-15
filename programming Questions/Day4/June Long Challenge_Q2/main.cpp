#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        if(s.size()<=1)
            cout<<0<<endl;
        else
        {
            long ct=0;
            for(long i=0;i<s.size();i++)
            {
                if((s[i]=='x' && s[i+1]=='y')||(s[i]=='y' && s[i+1]=='x'))
                {
                    ct++;
                    i++;
                }
            }
            cout<<ct<<endl;
        }
    }
    return 0;
}
