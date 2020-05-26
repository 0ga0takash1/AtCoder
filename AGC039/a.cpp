#include <bits/stdc++.h>
using namespace std;

#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())

int main() {
    string s;cin >> s;
    long long k;cin >> k;
    long long a = 1;
    std::vector<long long> v;
    long long ans;

    if ( s.length() > 2) {
        for (int i = 0; i < s.length(); ++i) {
            if ( s[i] != s[i+1] ) {
                if ( s[i] == s[i-1]) {
                    if (a != 1) {
                        v.push_back(a/2);
                        a = 1;
                    }
                } else {
                    a = 1;
                }
            } else {
                a++;
            }
        }
        if ( s[s.length()-1] != s[s.length()-2]
            && s[0] == s[s.length()-1]) {
            v.push_back(1);
        }
        a = accumulate(v.begin(), v.end(), 0LL);
    }

    ans = a*k;
    //cout << a << endl;
    if ( s.length() == 1 ) {
        cout << k/2 << endl;
    } else if ( k == 1 && s.length() == 2 ){
        cout << 0 << endl;
    } else if ( s[s.length()-1] != s[s.length()-2] && s[0] == s[s.length()-1]) {
        cout << ans-1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
