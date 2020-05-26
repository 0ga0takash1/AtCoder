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
std::vector<int> v;

int search ( string c[], int a, int b, int x, int y, int ans) {
    if ( c[x].at(y) == '#' ) {
        ans++;
    }
    if ( x == a && y == b ) {
        v.push_back(ans);
        return ans;
    }
    if ( x < a && y < b ) {
        search(c, a, b, x+1, y, ans);
        search(c, a, b, x, y+1, ans);
    } else if ( x == a ) {
        search(c, a, b, x, y+1, ans);
    } else if ( y == b ) {
        search(c, a, b, x+1, y, ans);
    }
}

int Goalable ( string c[], int a, int b ) {
    int ans = 0;
    if ( search(c, a, b, 0, 0, ans) == 0 ) {
        return 1;
    }
    return 0;
}

int main() {
    int h, w;
    cin >> h >> w;
    string s[h];
    int alldot = 0;
    int allsharp = 0;
    rep(i, h) {
        cin >> s[i];
        string keep = s[i];
        rep(j, w) {
            if ( keep[j] == '.' ) {
                alldot++;
            } else {
                allsharp++;
            }
        }
    }
    if ( alldot == h*w  || Goalable(s, h-1, w-1) ) {
        cout << 0 << endl;
        return 0;
    }

    if ( allsharp == h*w ) {
        cout << h+w-1 << endl;
        return 0;
    }

    int ans = 0;
    search(s, h-1, w-1, 0, 0, ans);
    Sort(v);
    cout << v.at(0) << endl;
    return 0;
}
