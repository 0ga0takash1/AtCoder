#include <bits/stdc++.h>
using namespace std;

#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
#define ALL(v) (v).begin(), (v).end()

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    vector<pair<int, int> > pairs(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pairs[i] = make_pair(i, a[i]);
    }

    sort(ALL(pairs), compare_by_b);
    for (int i = 1; i <= n; ++i) {
        cout << pairs[i].first << " ";
    }
    cout << endl;
    return 0;
}
