#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   int n;
    cin>>n;
   deque<pair<long long, long long>> a;
    for (int i = 0; i < n; i++){
       int type ;
        cin>>type;
        if (type == 1) {
            int number  , freq ;
            cin>>number>>freq;
            a.push_back({number, freq});
        }
        else {
            int number ;
            cin>>number;
            int sum=0;
            for (int j = 0; j < number && !a.empty(); j++) {
                sum+= a.front().second;
                a.pop_front();
            }
        }
    };
}
