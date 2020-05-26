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

const int inf = 0x3fffffff;
const ll INF = 0x3fffffffffffffff;
const ll mod = 1e9 + 7;

double nCr(double n , double r) {
    std::vector<std::vector<long double> > v(n + 1,std::vector<long double>(n + 1, 0));
    for (int i = 0; i < v.size(); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int j = 1; j < v.size(); j++) {
        for (int k = 1; k < j; k++) {
            v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
        }
    }
    return v[n][r];
}

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}
//vector<pair<int, int> > pairs(n+1);
//sort(ALL(pairs), compare_by_b);

void permutation(ll num, bool rev) {
    std::vector<ll> v;
    rep(i, num) {
        v.push_back(i);
    }

    if (!rev) {
        do {
            rep(i, num) {
                cout << v[i] << " ";
            }
        } while(next_permutation(ALL(v)));
    } else {
        do {
            rep(i, num) {
                cout << v[i] << " ";
            }
        } while(prev_permutation(ALL(v)));
    }
    cout << endl;
}

int main() {
    return 0;
}
