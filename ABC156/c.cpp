#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
#define ALL(v) (v).begin(), (v).end()

// π M_PI
// deg = rad*180/M_PI

int main() {
    int n;
    cin >> n;
    int x[n];
    std::vector<int> v;
    // int xx[n];
    // std::vector<int> vv;
    // int sum = 0;
    rep(i, n) {
        cin >> x[i];
        v.push_back(x[i]);
        // xx[i] = pow(x[i], 2);
        // vv.push_back(xx[i]);
        // sum += x[i];
    }
    // int ave = sum/n;
    std::vector<int> vv;
    for (ll i = 1; i <= *max_element(ALL(v)); ++i) {
        int sum = 0;
        rep(j, n) {
            sum += pow((x[j]-i), 2);
        }
        vv.push_back(sum);
    }

    cout << *min_element(ALL(vv)) << endl;
    return 0;
}
