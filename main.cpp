#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> P(n+1, 0);
        for (int i = 1; i <= n; i++) {
            P[i] = (P[i-1] + a[i-1]) % 3;
        }
        bool found = false;
        for (int l = 1; l <= n-2; l++) {
            for (int r = l+1; r <= n-1; r++) {
                int s1 = P[l] % 3;
                int s2 = (P[r] - P[l] + 3) % 3;
                int s3 = (P[n] - P[r] + 3) % 3;
                if ((s1 == s2 && s2 == s3) || (s1 != s2 && s1 != s3 && s2 != s3)) {
                    cout << l << " " << r << endl;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (!found) {
            cout << "0 0" << endl;
        }
    }
    return 0;
}