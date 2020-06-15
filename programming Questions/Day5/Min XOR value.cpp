#define ll long long

int Solution::findMinXor(vector<int> &A) 
{
    sort(A.begin(),A.end());
    ll mini=A[0]^A[1];
    for(ll i=1;i<A.size()-1;i++)
    {
        ll p=A[i]^A[i+1];
        mini=min(mini,p);
    }
    return int(mini);
}
