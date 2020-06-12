#include <bits/stdc++.h>
using namespace std;

#define n 36

int main()
{
    cout<<"Applying Linear Regression"<<endl;
    ifstream p("slr12.csv");
    string a,b;
    vector<double> X;
    vector<double> Y;
    vector<double> A; //x-mean_x
    vector<double> B; //y-mean_y
    vector<double> C; //estimated regression value : Y

    getline(p,a,','); // X
    getline(p,b,'\n'); // Y

    double mean_x,mean_y,sum1,sum2,i;
    while(p.good())
    {
        double c=0,d=0;
        getline(p,a,',');
        getline(p,b,'\n');
        for(i=0;i<a.length();i++)
            c=(c*10)+((double)(a[i])-48);
        X.push_back(c);
        for(i=0;i<b.length();i++)
            d=(d*10)+((double)(b[i])-48);
        Y.push_back(d);
    }

    sum1=accumulate(X.begin(),X.end(),0);
    sum2=accumulate(Y.begin(),Y.end(),0);

    mean_x=sum1/n;
    mean_y=sum2/n;
    //cout<<mean_x<<" "<<mean_y;

    for(i=0;i<n;i++)
    {
        A.push_back(X[i]-mean_x);
        B.push_back(Y[i]-mean_y);
    }

    sum1=0;
    sum2=0;

    for(i=0;i<n;i++)
    {
        sum1+=(A[i]*A[i]); //summation of(x-mean_x)^2
        sum2+=(A[i]*B[i]); //summation of(x-mean_x)(y-mean_y)
    }

    double m=sum2/sum1;   // slope= sum[(x-mean_x)(y-mean_y)]/sum[(x-mean_x)^2)
    double c=mean_y-(m*mean_x); // intercept

    cout<<"m= "<<m<<endl;
    cout<<"c= "<<c<<endl;

    cout<<"y = "<<m<<" x + "<<c;

    for(i=0;i<n;i++)             // storing estimated values
        C.push_back((m*X[i])+c);

    //////////////////////// Calculating R^2 //////////////////////////

    sum1=0;
    sum2=0;

    for(i=0;i<n;i++)             //sum[((estimated value-mean_y)^2)]
        sum1=sum1+((C[i]-mean_y)*(C[i]-mean_y)); //sum[(Ypred-y_mean)^2)]

    for(i=0;i<n;i++)
        sum2=sum2+((Y[i]-mean_y)*(Y[i]-mean_y)); ////sum[(Y-y_mean)^2)]

    double R=1-(sum1/sum2);
    cout<<"\nRsquare = "<<R<<endl;


/*    cout<<" X    Y     C\n";
    for(i=0;i<n;i++)
        cout<<X[i]<<" "<<Y[i]<<" "<<C[i]<<endl;
*/
    p.close();
    return 0;
}
