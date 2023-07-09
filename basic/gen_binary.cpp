#include <bits/stdc++.h>

using namespace std;

void create(vector<int>& a, int n) {
    for (int i = 1; i <= n; i++) {
        a[i] = 0;
    }
}

void binaryGen(vector<int>& a, int n, int& final) {
    // bat dau tu bit cuoi cung di tim bit 0 dau tien
    int i = n;
    while (i > 0 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i == 0) {
        final = 1; // day la cau hinh cuoi cung
    }
    else a[i] = 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, final  = 0;
    cin >> n;
    vector<int> a(n+1);
    while (!final) {
        for (int i = 1; i <= n; i++) {
            cout << a[i];
        }
        cout << endl;
        binaryGen(a, n, final);
    }
    return 0;
}