int Solution::divide(int b, int c) 
{
    long long bade=b;
    long long chote=c;
    bool neg=(bade<0)!=(chote<0);
    bade=(bade<0)? -bade :bade;
    chote=(chote<0) ? -chote :chote;
    long long res=0;
    
    while(bade>=chote)
    {
        long long temp=chote;
        long long add=1;
        while((temp<<1)<bade)
        {
            temp=temp<<1;
            add=add<<1;
        }
        res+=add;
        bade=bade-temp;
    }
    if(neg)
    {
        res=-res;
    }
    if(res>=2147483647)
        res= 2147483647;
    return res;
}
