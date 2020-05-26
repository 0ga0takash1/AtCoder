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

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main() {
    // コスパ魔法->止めの一撃
    int h, n;
    cin >> h >> n;
    int a[n], b[n];
    vector<pair<int, int> > pairs(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
        pairs.at(i).first = b[i];
        pairs.at(i).second = a[i]/b[i];
    }

    sort(ALL(pairs), compare_by_b);
    ll ans = 0;

    // コスパ魔法でけずる
    while ( h >= pairs.at(pairs.size()).first ) {
        h -= pairs.at(pairs.size()).first;
        ans += pairs.at(pairs.size()).first;
    }

    // 止めの一撃
    while (1) {
        /* code */
    }






    return 0;
}
