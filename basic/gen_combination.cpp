#include <bits/stdc++.h>

using namespace std;

void create(vector<int>& a, int k) {
    for (int i = 1; i <= k; i++) {
        a[i] = i;
    }
}

void combinationGen(vector<int>& a, int n, int& final, int k) {
    int i = k;
    while (i > 0 && a[i] == n-k+i) {
        i--;
    }
    if (i == 0) {
        final = 1; // day la cau hinh cuoi cung
    }
    else {
        a[i]++;
        for (int j = i+1; j <= k; j++) {
            a[j] = a[j-1] + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, final  = 0;
    cin >> n >> k;
    vector<int> a(k);
    create(a, k);
    while (!final) {
        for (int i = 1; i <= k; i++) {
            cout << a[i];
        }
        cout << endl;
        combinationGen(a, n, final, k);
    }
    return 0;
}