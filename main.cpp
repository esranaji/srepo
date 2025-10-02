#include <bits/stdc++.h>
using namespace std;




int main() {
    string s,t ;
    cin >> s >> t;
    deque<char> d;
    int count=0;
    bool flag=false;
    for (int i = 0; i < s.length(); i++) {
       d.push_back(s[i]);
    }
    for (int i = 0; i < t.length(); i++) {
         char c =d.back();
         d.pop_back();
        d.push_front(c);
        if (t==string(d.begin() , d.end()));
    }

}
