#include <bits/stdc++.h>
using namespace std;

#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
#define ll long long
/*
bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}
*/
int main() {
    ll n;
    cin >> n;
    ll x, y;
    std::vector<ll> v;
    for (int i = 1; i <= sqrt(n); ++i) {
        if ( n%i == 0 ) {
            x = n/i;
            y = i;
            v.push_back(x+y-2);
        }
    }
    cout << *min_element(v.begin(), v.end()) << endl;
/*
    //vector<pair<ll, ll> > pairs(n);
    //int num = 0;

    if ( sqrt(n) == (int)sqrt(n) ) {
        x = sqrt(n);
        y = x;
    } else {
        for (int i = 2; i < n/2; ++i) {
            if ( n%i == 0 ) {
                //cout << "a" << i << endl;
                flag = 1;
                //int xx = n/i;
                //int yy = i;
                //pairs[num] = make_pair(n/i, (n/i)+i-2);
                //num++;
                if ( x < n/i ) {
                    x = n/i;
                }
            }
        }

        if (pairs.size() > 1) {
            sort(pairs.begin(), pairs.end(), compare_by_b);
            x = pairs[0].first;
        } else {
            x = pairs[0].first;
        }

        //reverse(pairs.begin(), pairs.end());
        y = n/x;
    }

    if ( flag == 0 ) {
        x = 1;
        y = n;
        ans = x+y-2;
    }
    //cout << x << " " << y << endl;
    ans = x+y-2;
    cout << ans << endl;
*/
/*
    ll x, y;
    ll ans = pow(10, 12);
    for (int i = 2; i < n/2; ++i) {
        if ( n%i == 0 ) {
            flag = 1;
            ll num = (n/i)+i-2;
            //cout << "a" << num << endl;
            if ( ans > num && num != 0 ) {
                //x = n/i;
                ans = num;
            }
        }
        //cout << ans << endl;
    }

    if ( flag == 0 ) {
        x = 1;
        y = n;
        ans = x+y-2;
    }
    cout << ans << endl;
*/
    return 0;
}
