int Solution::singleNumber(const vector<int> &A) 
{
    int result;
    for(int i=0;i<A.size();i++)
    {
        result=result^A[i];
    }
    return result;
}
