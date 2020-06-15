unsigned int Solution::reverse(unsigned int A) 
{
    unsigned int res=0;
    int pw=31;
    while(A>0)
    {
        int rem=A%2;
        res=res+(rem*pow(2,pw));
        pw--;
        A=A/2;
    }
    return res;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
