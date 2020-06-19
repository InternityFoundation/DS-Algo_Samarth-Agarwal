int Solution::lis(const vector<int> &A) 
{
    int n=A.size();
    if(n<=1)
        return 1;
    vector<int> lis(n,1);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(A[i]>A[j] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }
    return *max_element(lis.begin(),lis.end());
}
