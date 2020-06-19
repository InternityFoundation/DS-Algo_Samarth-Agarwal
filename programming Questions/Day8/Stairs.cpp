int solve(int A,int dp[])
{
    if(A<=1)
        return 1;
    if(dp[A]!=0)
        return dp[A];
    
    return dp[A]=solve(A-1,dp)+solve(A-2,dp);
}


int Solution::climbStairs(int A) 
{
    int dp[37]={0};
    return solve(A,dp);
}
