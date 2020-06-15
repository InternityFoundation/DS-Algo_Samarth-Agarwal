#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v ;

void get_ans(int i,int n,int a[],int sum,int check)
{

if(check==1)v.push_back(sum) ;    
    
if(i>=n)return ;

get_ans(i+1,n,a,sum + a[i],1) ;

get_ans(i+1,n,a,sum,0) ;
    
}




int main() {
int t ;
cin>>t;
while(t--){
v.clear() ;
int n;
cin>>n ;
int a[n] ;
for(int i=0;i<n;i++)cin>>a[i] ;

get_ans(0,n,a,0,1);

sort(v.begin(),v.end()) ;

for(auto it= v.begin() ; it != v.end() ; it++)
cout<<*it<<" " ;

cout<<endl ;

}
}