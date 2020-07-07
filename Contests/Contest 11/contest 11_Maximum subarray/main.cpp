#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n;
    cin>>n;
    long arr[n];
    for(long i=0;i<n;i++)
        cin>>arr[i];
    long lim;
    cin>>lim;
    long len=n;
    long minIndex = 0, maxIndex = 0;
    long start = 0, endi = 0;
    long maxLength = 0;
    for (long i = 1; i < len; i++)
    {
        endi = i;
        if (arr[i] < arr[minIndex])
            minIndex = i;
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
        if (arr[maxIndex] - arr[minIndex] > lim)
        {
            if (endi - start > maxLength)
                maxLength = endi - start;
            start++;
            maxIndex = minIndex = start;
            i = start;
        }
    }
    cout<<maxLength;
    return 0;
}
