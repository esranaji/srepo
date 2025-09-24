#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t ;
    cin >> t;
    while(t--) {
        int u ,v ;
        cin >> u >> v ;
        ll mx=max(u,v);
        ll mn = min(u,v);
         ll ans1=(mn*mn) ;
        ll ans2=-1*(mx*mx) ;
        cout<<ans1<<" "<<ans2 <<endl;
    }
}
/**/