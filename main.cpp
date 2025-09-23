#include <iostream>
#include <map>
#include <vector>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
 vector<int>v ;
int sub=0;
int sum(int l ,int r) {
    sub=0;
  for (int i=l;i<=r;i++) {
      sub+=v[i];
  }
    return sub;


}
int main() {
    int t ;
    cin >>t ;
    while (t--) {
        v.clear();
        int n;
        cin>>n;

        for (int i=0;i<n;i++) {
            int x ;
            cin>>x;
            v.push_back(x);
        }
        int ansl=0 ,ansr=0;
        bool f=false;
        for (int l=0;l<n;l++) {

            for (int r=l+1;r<n-1;r++) {
                set<int>set;
                int s1=sum(0,l)%3;
                int s2=sum(l+1,r)%3;
                int s3=sum(r+1,n-1)%3;
                set.insert(s1);
                set.insert(s2);
                set.insert(s3);
                if ((int)set.size()==3 || (int)set.size()==1) {
                    ansl=l;
                    ansr=r;
                    f=true ; break;
                }

            }
            if (f)break;;
        }
      if (f)
        cout<<ansl+1<<" "<<ansr+1<<endl;
        else cout<<0<<" "<<0<<endl;
    }
}
