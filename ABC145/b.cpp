#include <bits/stdc++.h>
using namespace std;

#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
typedef long long ll;
typedef int64_t i6;
//π M_PI
//deg = rad*180/M_PI

int main() {
    int n;
    string s;
    cin >> n >> s;
    bool flag = false;
    int ans = 0;
    if ( s.length()%2 == 0 ) {
        for (int i = 0; i < s.length()/2; ++i) {
            if ( s[i] == s[i+(s.length()/2)]) {
                ans++;
            }
        }

        if ( ans == (s.length()/2)) {
            flag = true;
        }
    }

    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}
