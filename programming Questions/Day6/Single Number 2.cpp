int Solution::singleNumber(const vector<int> &A) 
{
    int num_0 = 0;
    int num_1 = 0;
    int a=0;
    for(int x=0; x<31; x++)
    {
        num_0 = 0;
        num_1 = 0;
        for(int y=0; y<A.size(); y++)
        {
            if(A[y]&(1<<x)) //counting number of 1's at each bit position
                num_1++;
            else
                num_0++;
        }
        if(num_1%3 == 1)
            a|=(1<<x);
    }
    return a;
}
