#include <bits/stdc++.h>
using namespace std;

long nCr(int n, int r) {
    long ans = 1;
    for (int i = n; i > n - r; --i) {
        ans = ans*i;
    }
    for (int i = 1 ; i < r + 1; ++i) {
        ans = ans / i;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<char> > v;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<char> vv;
        for (int j = 0; j < 10; j++) {
            vv.push_back(s[j]);
        }

        sort(vv.begin(), vv.end());
        v.push_back(vv);
    }
    sort(v.begin(), v.end());

    long long ans = 0;
    int num = 0;
    for (int i = 0; i < n-1; i++) {
        if ( i < num ) {
            continue;
        }
        for (int j = i+1; j < n; j++) {
            if ( v[i] == v[j] ) {
                //ans++;
                num = j;
            } else {
                break;
            }
        }

        ans += (num*(num-1))/2;
        cout << num << nCr(num, 2) << endl;
    }

    cout << ans << endl;
}
