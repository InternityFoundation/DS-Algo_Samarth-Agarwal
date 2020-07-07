#include <bits/stdc++.h>
using namespace std;

int cmpr(string s1,string s2)
{
    if(s1.append(s2).compare(s2.append(s1))>0)
        return 1;
    else
        return 0;
}


void max_number(vector<string> A)
{
    long i,s=A.size();
    sort(A.begin(),A.end(),cmpr);
	if(A[0]=="0")
		cout<<"0";
	else
	{
    	for(i=0;i<s;i++)
        	cout<<A[i];
	}
}


int main()
{
    long n;
    cin>>n;
    vector<string> A;
    long i;
    for(i=0;i<n;i++)
    {
        string p;
        cin>>p;
        A.push_back(p);
    }
    max_number(A);

    return 0;
}
