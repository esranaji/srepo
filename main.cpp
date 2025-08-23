#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <deque>
using namespace std;
#define ll long long
const int MOD = 1000000007;


vector<ll> generate_primes(ll limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= limit; ++i) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= limit; j += i)
                is_prime[j] = false;
        }
    }
    vector<ll> primes;
    for (ll i = 2; i <= limit; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
    return primes;
}


map<long long, int> factorize(long long num) {
    map<long long, int> factors;

    // نقسم على 2 أولاً لتسريع العملية
    while (num % 2 == 0) {
        factors[2]++;
        num /= 2;
    }

    // نقسم على الأعداد الفردية فقط
    for (long long i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            factors[i]++;
            num /= i;
        }
    }

    // لو العدد المتبقي أولي كبير
    if (num > 1)
        factors[num]++;

    return factors;
}

string toBinary(int n) {
    if(n == 0) return "0";
    string binary = "";
    while(n > 0) {
        binary = char('0' + (n % 2)) + binary;
        n /= 2;
    }
    return binary;
}

#include <bits/stdc++.h>
using namespace std;
using u128 = __uint128_t;
using u64 = unsigned long long;

// دالة الضرب بالموديل
u64 mulmod(u64 a, u64 b, u64 mod) {
    return (u128)a * b % mod;
}

// دالة الرفع السريع للقوة (binary exponentiation)
u64 powmod(u64 a, u64 e, u64 mod) {
    u64 res = 1;
    while (e) {
        if (e & 1) res = mulmod(res, a, mod);
        a = mulmod(a, a, mod);
        e >>= 1;
    }
    return res;
}

// اختبار Miller-Rabin
bool isPrime(u64 n) {
    if (n < 2) return false;
    // أعداد صغيرة
    for (u64 p : {2,3,5,7,11,13,17,19,23,29,31,37}) {
        if (n%p==0) return n==p;
    }
    // اكتب n-1 = 2^s * d
    u64 d = n-1, s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
    // قيم a تكفي للأعداد <= 2^64
    for (u64 a : {2,325,9375,28178,450775,9780504,1795265022}) {
        if (a % n == 0) continue;
        u64 x = powmod(a, d, n);
        if (x == 1 || x == n-1) continue;
        bool composite = true;
        for (u64 r = 1; r < s; r++) {
            x = mulmod(x, x, n);
            if (x == n-1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}

int main() {
    int t ;
    cin >> t;
    while(t--) {
        int n ,sum=0 ;
        cin >> n;
        vector<int> a(n), b(n) ;

       for (int i = 0; i < n; i++) {
          cin>>a[i];
       }
        for (int i = 0; i < n; i++) {
            cin>>b[i];
        }

        for (int i = 0; i < n; i++) {
            if (a[i]-b[i]>0)sum+=a[i]-b[i];
        }
        cout << sum+1<< endl;

    }
}
