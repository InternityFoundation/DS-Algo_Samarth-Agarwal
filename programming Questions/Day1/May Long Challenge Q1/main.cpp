#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        vector<int> X;
        int i,j;
        for(i=0;i<N;i++)
        {
            cin>>j;
            X.push_back(j);
        }
        map<int,int> m;
        for(i=1;i<N;i++)
        {
            //cout<<i<<endl;
            for(j=i-1;j>=0;j--)
            {
                if((X[j+1]-X[j])<=2)
                {
                    m[i]++;
                    m[j]++;
                }
                else
                    break;
                //cout<<m[0]<<m[1]<<m[2]<<m[3]<<m[4]<<endl;
            }
        }
        map<int,int>::iterator p=m.begin();
        int mini=m[0];
        int maxi=m[0];
        while(p!=m.end())
        {
            if(p->second<mini)
                mini=p->second;
            if(p->second>maxi)
                maxi=p->second;
            p++;
        }
        cout<<mini+1<<" "<<maxi+1<<endl;
    }
    return 0;
}
