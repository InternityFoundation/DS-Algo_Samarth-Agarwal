//This is The Coding Area
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
double fact(ll n)
{
    double res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}

ll modInverse(ll a, ll m)
{
    a = a%m;
    for (int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll T;
  cin>>T;
  ll n,t,m;
  while(T--)
  {
      cin>>n>>t>>m;
      //double failprob=(fact(n-m)*fact(n-t))/(fact(n)*fact(n-m-t));
      ll p=fact(n-m)*fact(n-t);
      ll q=fact(n)*fact(n-m-t);
      //double output=1-failprob;
      while(__gcd(p,q)!=1)
      {
          p=p/__gcd(p,q);
          q=q/__gcd(p,q);
      }
      //cout<<output;
      p=q-p;
      cout<<((p%mod)*(modInverse(q,mod))%mod)%mod<<endl;
  }
  return 0;
}

