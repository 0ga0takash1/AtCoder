#include <bits/stdc++.h>
using namespace std;

#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
#define ll long long

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 1;
    for (int i = 0; i < n-1; ++i) {
        if ( s[i] != s[i+1]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
