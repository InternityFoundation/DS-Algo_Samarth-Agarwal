#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;

    stack<int> s;
    s.push(-1);

    int max_len=0;
    int n=str.size();
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(')
            s.push(i);
        else
        {
            s.pop();
            if(!s.empty())
                max_len=max(max_len,i-s.top());
            else
                s.push(i);
        }
    }
    cout<<max_len;

    return 0;
}
