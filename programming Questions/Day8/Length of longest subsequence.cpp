int Solution::longestSubsequenceLength(const vector<int> &A) 
{
    int n=A.size();
    if(n<=1)
        return n;
    int i,j;
    //Find longest increasing subsequence upto each i
    vector<int> lis(n,1);
    
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(A[i]>A[j] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }
    
    //Find longest decreasing subsequence from each i 
    vector<int> lds(n,1);
    for(i=n-2;i>=0;i--)
    {
        for(j=n-1;j>i;j--)
        {
            if(A[i]>A[j] && lds[i]<lds[j]+1)
                lds[i]=lds[j]+1;
        }
    }
    
    //Find maximum of [LIS+LDS-1]
    int maxi=lis[0]+lds[0]-1;
    for(i=1;i<n;i++)
    {
        maxi=max(maxi,lis[i]+lds[i]-1);
    }
    return maxi;
}
