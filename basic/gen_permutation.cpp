#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    do {
        for (int i = 0; i < n; i++) {
            cout << a[i];
        }
        cout << endl;
    } while(next_permutation(a.begin(), a.end()));

    do {
        for (int i = 0; i < n; i++) {
            cout << a[i];
        }
        cout << endl;
    } while(prev_permutation(a.begin(), a.end()));

    return 0;
}