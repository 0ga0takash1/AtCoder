#include <bits/stdc++.h>
using namespace std;

#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
#define ll long long
//π M_PI
//deg = rad*180/M_PI

int main() {
    string s;
    cin >> s;
    if ( s.length() == 1 ) {
        cout << 1 << endl;
        return 0;
    }
    std::vector<ll> v;
    ll num = 0;
    if ( s[0] == '<' ) {
        v.push_back(0);
    } else {
        num++;
    }
    bool keep = false; //<>keep
    ll keep_num;

    for (ll i = 1; i < s.length(); ++i) {
        if ( s[i] == '<' ) {
            if ( s[i-1] == '<' ) {
                v.push_back(v[v.size()-1]+1);
            } else {
                if (keep) {
                    if ( keep_num >= num ) {
                        v.push_back(keep_num+1);
                        num--;
                    }
                }
                v.push_back( ((num+1)*num)/2 );
                v.push_back(0);
                num = 0;
                keep = false;
            }
        } else { //>
            if ( s[i-1] == '<' ) {
                keep = true;
                keep_num = v[v.size()-1];
                num++;
                if ( i == s.length()-1 ) {
                    if ( s[s.length()-2] == '<') {
                        v.push_back(v[v.size()-1]+1);
                    } else {
                        v.push_back(1);
                    }
                    v.push_back(0);
                }
            } else {
                num++;
                if ( i == s.length()-1 ) {
                    if (keep) {
                        keep = false;
                        if ( keep_num >= num ) {
                            v.push_back(keep_num+1);
                        }
                    }
                    v.push_back( ((num+1)*num)/2 );
                    v.push_back(0);
                }
            }
        }

        if ( i == s.length()-1 ) {
            if ( s[i] == '<' ) {
                v.push_back(v[v.size()-1]+1);
            }
        }
    }
    cout << accumulate(v.begin(), v.end(), 0LL) << endl;
    return 0;
}
