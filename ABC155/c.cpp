#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
#define ALL(v) (v).begin(), (v).end()

//π M_PI
//deg = rad*180/M_PI
/*
bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}
*/
bool pairCompare(const pair<string, ll>& firstElof, const pair<string, ll>& secondElof)
{
    return firstElof.second < secondElof.second;
}

int main() {
    ll n;
    cin >> n;
    string s[n];
    std::vector<string> v;
    rep(i, n) {
        cin >> s[i];
        v.push_back(s[i]);
    }
    Sort(v);

    vector<pair<string, ll> > pairs;
    string temp = v[0];
    ll count = 0;
    rep(i, n) {
        if ( i != 0 ) {
            if ( temp == v[i] ) {
                count++;
            } else {
                pairs.push_back( make_pair(temp, count) );
                count = 0;
                temp = v[i];
            }
        }
    }
    pairs.push_back( make_pair(temp, count) );
    sort(ALL(pairs), pairCompare);
    reverse(ALL(pairs));
    ll num = pairs[0].second;
    std::vector<string> v2;
    rep(i, n) {
        v2.push_back(pairs[i].first);
        if ( i != n-1 && num != pairs[i+1].second ) {
            break;
        }
    }
    Sort(v2);
    rep(i, v2.size()) {
        cout << v2[i] << endl;
    }
/*
    string s[n];
    vector<pair<ll, ll> > pairs;
    rep(i, n) {
        // pairs.at(i).first = i;
        // pairs.at(i).second = 0;
        pairs.push_back( make_pair(i, 0) );
    }
    std::vector<string> vv;
    int over_half = 0;
    rep(i, n) {
        cin >> s[i];
        vv.push_back(s[i]);
        if ( !over_half ) {
            if ( i == 0 ) {
                pairs.at(i).second++;
            } else {
                int aa = 0;
                rep(j, i) {
                    if ( s[i] == s[j] ) {
                         pairs.at(j).second++;
                         aa = 1;
                         break;
                    }
                }
                if (!aa) {
                    pairs.at(i).second++;
                }
            }
            if ( pairs.at(i).second > n/2) {
                over_half = 1;
            }
        }
    }

    sort(ALL(pairs), compare_by_b);
    // reverse(ALL(pairs));
    int b = pairs.at(pairs.size()-1).second;
    if ( b == 1 ) {
        Sort(vv);
        rep(i, n) {
            cout << vv.at(i) << endl;
        }
    } else {
        std::vector<string> v;
        rep(i, n) {
            v.push_back(s[pairs.at(i).first]);
            if ( pairs.at(i+1).second != b ) {
                break;
            }
        }
        Sort(v);
        rep(i, v.size()) {
            cout << v.at(i) << endl;
        }
    }
*/
/*
    vector<pair<string, ll> > pairs(n+1);
    rep(i, n+1) {
        pairs.at(i).second = 0;
    }
    ll size = 0;
    rep(i, n) {
        string s;
        cin >> s;
        if ( i == 0 ) {
            pairs.at(i).first = s;
            pairs.at(i).second = 1;
            size++;
        } else {
            int aa = 0;
            rep(j, size) {
                if ( s == pairs.at(j).first ) {
                     pairs.at(j).second++;
                     aa = 1;
                     break;
                }
            }
            if (!aa) {
                pairs.at(size).first = s[i];
                pairs.at(size).second = 1;
                size++;
            }
        }
    }

    sort(ALL(pairs), compare_by_b);
    reverse(ALL(pairs));
    int b = pairs.at(0).second;
    std::vector<string> v;
    rep(i, n) {
        v.push_back(pairs.at(i).first);
        if ( pairs.at(i+1).second != b ) {
            break;
        }
    }
    Sort(v);
    rep(i, v.size()) {
        cout << v.at(i) << endl;
    }
*/
    return 0;
}
