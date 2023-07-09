#include <bits/stdc++.h>

using namespace std;

int gcd (int a, int b) {
    if (a < b) swap(a, b);
    while(b) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b; cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}