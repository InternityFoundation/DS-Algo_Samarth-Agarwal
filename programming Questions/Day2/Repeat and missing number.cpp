#define ll long long
vector<int> Solution::repeatedNumber(const vector<int> &A) 
{
    vector<int> B;
    ll s1=0,i,n1=1,n=1,s=0;
    for(i=1;i<=A.size();i++)
    {
        s+=i;
        n*=i;
    }
    for(i=0;i<A.size();i++)
    {
        n1*=(ll)(A[i]);
        s1+=(ll)(A[i]);
    }
    ll diff=s1-s;
    ll x=n1-n;
    ll a=(diff*n1)/x;
    ll b=(a*n)/n1;
    B.push_back(int(a));
    B.push_back(int(b));
    return B;
}
