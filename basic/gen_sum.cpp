#include <bits/stdc++.h>

using namespace std;

void gen_sum(vector<int>& a, int n, int& cnt, int& final) {
    int i = cnt;
    while (i > 0 && a[i] == 1) {
        i--;
    }
    if (i == 0) {
        final = 1;
    }
    else {
        a[i]--;
        int d = cnt - i + 1;
        cnt = i;
        int q = d / a[i];
        int r = d % a[i];
        if (q) {
            for (int j = 1; j <= q; j++) {
                cnt++;
                a[cnt] = a[i];
            }
        }
        if(r) {
            cnt++;
            a[cnt] = r;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int cnt = 1, final = 0;
    vector<int> a(n+1);
    a[1] = n;
    while (!final) {
        for (int i = 1; i <= cnt; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        gen_sum(a, n, cnt, final);
    }

    return 0;
}