int Solution::maxSubArray(const vector<int> &A) 
{
    int s=A.size();
    int max_so_far=A[0];
    int curr_max=A[0];
    for(int i=1;i<s;i++)
    {
        curr_max=max(A[i],curr_max+A[i]);
        max_so_far=max(max_so_far,curr_max);
    }
    return max_so_far;
}
