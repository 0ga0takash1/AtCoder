#include <bits/stdc++.h>
using namespace std;

#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
#define ll long long
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
    ll n;
    cin >> n;
    ll L[n], R[n];
    vector<pair<ll, ll> > pairs(n);
    vector<pair<ll, ll> > num(n);
    for (int i = 0; i < n; ++i) {
        cin >> L[i] >> R[i];
        pairs[i] = make_pair(i, R[i]-L[i]);
        //num[i] = make_pair(i, L[i]);
    }
    sort(pairs.begin(), pairs.end(), compare_by_b);
    //sort(num.begin(), num.end(), compare_by_b);

    cout << pairs[0].second+pairs[1].second << endl;
    return 0;
}
