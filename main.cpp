#include <bits/stdc++.h>
using namespace std;

int main() {
   int t;
   cin>>t;
   while(t--) {
       int n,k;
       cin>>n>>k;
       map<int,int> mp;
       for(int i=0;i<n;i++) {
           mp[i]=0;
       }
       for(int i=0;i<n;i++) {
           int x;
           cin>>x;
           mp[x]++;
       }
       int count=0;
      int countk=0;
       for (auto [k1,v] : mp) {
           if (k1<k && v==0)
               count++;
           else if (k1==k)
               countk=v;

       }

       cout<<max(count,countk)<<endl;
   }
}
