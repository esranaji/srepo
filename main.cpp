#include <bits/stdc++.h>
#define  ll long long
using namespace std;



const int MOD = 1e9 + 7;

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ;
    cin>>t ;
    while(t--) {
        int n ,k, ans=0;
        cin>>n>>k;
        vector< vector<int>>v (n,vector<int> (3));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                cin>>v[i][j];
            }
        }
        sort(v.begin(), v.end(),[](const vector<int>& a, const vector<int>& b) {
            return a.back() < b.back();
        });

/*
 * 
 */
        for (int i = 0; i < n; i++) {
            if (v[i][0] <=k && v[i][1]>=k )
                k=max(v[i][2],k);
        }
   cout<<k<<endl;
    }

/*
    1
    4 6
    1 3 2
    2 5 5
    6 10 10
    8 12 12
 */
}
