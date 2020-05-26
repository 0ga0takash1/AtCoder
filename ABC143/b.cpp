#include <bits/stdc++.h>
using namespace std;

#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
#define ll long long

int main() {
    int n;
    cin >> n;
    int d[n];
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    std::vector<int> v;
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            v.push_back(d[i]*d[j]);
        }
    }
    cout << accumulate(v.begin(),  v.end(), 0) << endl;
    return 0;
}
