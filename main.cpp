#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <deque>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


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


    while (num % 2 == 0) {
        factors[2]++;
        num /= 2;
    }


    for (long long i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            factors[i]++;
            num /= i;
        }
    }


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


u64 mulmod(u64 a, u64 b, u64 mod) {
    return (u128)a * b % mod;
}


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

void Speed() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

pair<int,int > rem(int x ,int k) {
    int r=x%k;
    int r2=(k-r)%k;
    return {r,r2};
}
#include <bits/stdc++.h>
using namespace std;


#include <bits/stdc++.h>
using namespace std;

string addStrings(const string &a, const string &b) {
    int i = (int)a.size() - 1, j = (int)b.size() - 1, carry = 0;
    string res;
    while (i >= 0 || j >= 0 || carry) {
        int x = (i >= 0 ? a[i--] - '0' : 0);
        int y = (j >= 0 ? b[j--] - '0' : 0);
        int s = x + y + carry;
        res.push_back(char('0' + (s % 10)));
        carry = s / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}




string decimalToBase(long long n, int base) {
    if (n == 0) return "0";

    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result = "";

    while (n > 0) {
        int rem = n % base;
        result.push_back(digits[rem]);
        n /= base;
    }

    reverse(result.begin(), result.end());
    return result;
}


long long baseToDecimal(string num, int base) {
    long long result = 0;
    for (char c : num) {
        int val;
        if (isdigit(c)) val = c - '0';
        else val = c - 'A' + 10;
        result = result * base + val;
    }
    return result;
}

long long modpow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}



int main() {
    int n,gold ;
    cin >>n >>gold;
    vector<int>v;
    for (int i = 0; i < n; i++) {
        int x ;cin >>x ;
        v.push_back(x);
    }
    int l=0  ,sum=0,mn=INT_MAX;

    for (int i = 0; i < v.size(); i++) {

        sum+=v[i];

        while (sum>=gold) {
            mn=min(mn,i-l+1);
            sum-=v[l];
            l++;

        }
    }
    //cout<<(mn==INT_MAX?-1 : mn)<<" ";
}


