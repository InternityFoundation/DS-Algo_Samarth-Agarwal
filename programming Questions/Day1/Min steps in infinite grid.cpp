int Solution::coverPoints(vector<int> &A, vector<int> &B) 
{
    int size=A.size();
    int ct=0;
    int x=A[0];
    int y=B[0];
    for(int i=1;i<size;i++)
    {
        int m=A[i];
        int n=B[i];
        ct+=max(abs(m-x),abs(n-y));
        x=A[i];
        y=B[i];
    }
    return ct;
}
