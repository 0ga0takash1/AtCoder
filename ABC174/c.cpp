#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;
typedef std::vector<std::vector<int64_t> > Graph;

#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define repb(i, l, n) for (int64_t i = l; i < n; ++i)
#define repb2(i, l, n) for (int64_t i = l; i <= n; ++i)
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define Push_back(p, a, b) (p).push_back( make_pair( (a), (b) ) )

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

// vector<int64_t>
void enum_div(int64_t n) {
    // vector<int64_t> ret;
    cout << "f " << n << endl;
    for(int i = 1 ; i*i <= n ; ++i){
        if(n%i == 0){
            // ret.push_back(i);
            cout << i << " ";
            if(i != 1 && i*i != n){
                // ret.push_back(n/i);
                cout << n/i << " ";
            }
        }
    }
    cout << endl;
    return;
    /*
    rep(i, ret.size()) {
        cout << "a " << ret[i] << endl;
    }
    return ret;*/
}

const int64_t INF = 0x3fffffffffffffff;

int main() {
    int64_t n;
    cin >> n;
    std::vector<int64_t> v;
    v.push_back(7);
    while (v.at(v.size()-1) <= 7777777777) {
        enum_div(v.at(v.size()-1));
        v.push_back((v.at(v.size()-1)*10)+7);
    }
    /*
    if ( n%2 == 0 ) {
        cout << -1 << endl;
    } else {

    }*/
    return 0;
}
