#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 1; i <= n; ++i)
#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
#define ALL(v) (v).begin(), (v).end()

// π M_PI
// deg = rad*180/M_PI

struct Node {
    ll num;
    Node* next[200000];
    Node* before[200000];
};

int No_next ( Node *n ) {
    if ( !n->next[0] ) {
        return 1;
    }
    return 0;
}

bool pairCompare(const pair<ll, ll>& firstElof, const pair<ll, ll>& secondElof) {
    return firstElof.first < secondElof.first;
}

int main() {
    ll n;
    cin >> n;
    ll a[n], b[n];
    vector<pair<ll, ll> > p;
    rep(i, n-1) {
        cin >> a[i] >> b[i];
        p.push_back( make_pair(a[i], b[i]) );
    }
    sort(ALL(p), pairCompare);

    int tree = 0;

    rep(i, n-1) {
        // p.at(i).first
    }

    ll ans[n];
    if ( !tree ) {
        cout << -1 << endl;
    } else {
        rep(i, n) {
            cout << ans[i] << " ";
        }
    }
    return 0;
}
