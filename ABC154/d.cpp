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

int main() {
    ll n;
    double k;
    cin >> n >> k;
    double p[n];
    double expect[n];
    std::vector<double> v;
    std::vector<double> v2;
    rep(i, n) {
        cin >> p[i];
        expect[i] = (1+p[i])/2;
        v.push_back(expect[i]);
        double num = 0.0;
        if (i >= k) {
            rep(j, k) {
                num += v.at(i-j);
            }
            v2.push_back(num);
        }
    }
    Sort_rev(v2);
    cout <<  setprecision(12) << v2.at(0) << endl;
    return 0;
}
