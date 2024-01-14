#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
 
const int base = 331;
const int mod = 1e9 + 7;
const int maxn = 5*1e5 + 10;

int POW[maxn], hashT[maxn];

int hash_value_of_string(string& s) {
    int hash = 0;
    for (int i = 1; i < s.size(); i++) {
        hash = (hash * base + (s[i] - 'a' + 1)) % mod;
    }
    return hash;
}

// Precalculate base^i
void cal_base_i(string& s) {
    for (int i = 1; i < s.size(); i++) {
        POW[i] = (POW[i-1] * base) % mod;
    }
}

// Calculate hash value of T[1..i]
void cal_hase_T(string& s) {
    for (int i = 1; i < s.size(); i++) {
        hashT[i] = (hashT[i-1] * base + (s[i] - 'a' + 1)) % mod;
    }
}

int getHashT(int i, int j) {
    return (hashT[j] - hashT[i-1] * POW[j-i+1] + mod * mod) % mod;
}

void solve() {
    string T, P;
    cin >> T >> P;

    // Initialize
    int lenT = T.size(), lenP = P.size();
    T = " " + T;
    P = " " + P;
    POW[0] = 1;

    int hashP = hash_value_of_string(P);
    cal_base_i(T);
    cal_hase_T(T);
    for (int i = 1; i <= lenT - lenP + 1; i++) {
        if (hashP == getHashT(i, i + lenP - 1)) {
            cout << i-1 << " ";
        }
    }
    cout << endl;
}
 
int32_t main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
	
    int t; cin >> t;
    while (t--) solve();
    
    return 0;
}