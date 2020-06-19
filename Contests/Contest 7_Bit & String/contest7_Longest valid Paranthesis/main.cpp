#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin>>str;
    if(str.size()<=1)
        cout<<0;
    else
    {
        stack<int> S;
        S.push(-1);
        int maxL=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='(')
                S.push(i);
            else
            {
                S.pop();
                if(S.empty())
                    S.push(i);
                else
                    maxL=max(i-S.top(),maxL);
            }
        }
        cout<<maxL;
    }
	return 0;
}
