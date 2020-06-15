int Solution::cntBits(vector<int> &A) 
{
    long long mod=1000000007,ans=0;
    for(int i=0;i<32;i++)
    {
        long long ct=0;
        for(int j=0;j<A.size();j++)
        {
            if(A[j]&(1<<i))
                ct++;
        }
        ans=((ans%mod)+((ct)*((A.size()-ct)*2)%mod))%mod;
    }
    return ans;
    
}
