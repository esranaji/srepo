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

bool prime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int LCS(string a, string b) {
    int mxlen = 0;
    int mn = min(a.length(), b.length());

    for (int len = 1; len <= mn; len++) {
        for (int i = 0; i + len <= a.length(); i++) {
            for (int j = 0; j + len <= b.length(); j++) {
                string s1 = a.substr(i, len);
                string s2 = b.substr(j, len);
                if (s1 == s2) {
                    mxlen = max(mxlen, len);
                }
            }
        }
    }
    return mxlen;
}

ll add(ll a, ll b) {
    return ( (a % MOD) + (b % MOD) ) % MOD;
}

ll sub(ll a, ll b) {
    return ( ( (a % MOD) - (b % MOD) ) + MOD ) % MOD;
}

ll mul(ll a, ll b) {
    return ( (a % MOD) * (b % MOD) ) % MOD;
}

void solve (string a , ll  b ) {
    ll ans=0 , powerten=1 ;
    for (int i = a.size()-1 ; i >=0 ; i--) {
        int digit = (a[i] - '0' );
        ans+=(digit %b * powerten % b) %b ;
        ans %= b;

        powerten*=10 %b ;
        powerten %= b;

    }
    cout<< ans<<endl;
}
/////////////////

vector<bool> prime;
vector<int> primes;
vector<ll> primeFactors(ll n) {
    vector<ll> factors;


    while (n % 2 == 0) {
        factors.push_back(2);
        n = n / 2;
    }


    for (ll i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n = n / i;
        }

    }
    if (n > 2) {
        factors.push_back(n);
    }

    return factors;
}
void Sieve(int n) {
    prime.assign(n + 1, true);
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= n / i; i++) {
        if (!prime[i])continue;

        for (int j = i * i; j <= n; j += i) {
            prime[j] = 0;
        }

    }
    for (int i = 2; i <= n; i++) {
        if (prime[i])primes.push_back(i);
    }
}

///////////
map<int, int> mp;
void fact(int n) {
    for (auto p : primes) {
        if (p*p>n)break;
        if (n % p == 0) {
            n/=p;
            mp[p]++;
        }

    }
    if (n>1)mp[n]++;
}
////////////////
string toBinary(int n) {
    if(n == 0) return "0";
    string binary = "";
    while(n > 0) {
        binary = char('0' + (n % 2)) + binary;
        n /= 2;
    }
    return binary;
}



void Speed() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}



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

vector<ll> getDivisors(ll n) {
    vector<ll> divisors;
    for (int i = 1; 1LL * i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i)
                divisors.push_back(n / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}


ll fastPower(ll n, ll p) {
    if (p == 1) return n;
    ll res = fastPower(n*n, p / 2);
    if (p & 1) res = mul(res, n);
    return res;
}

