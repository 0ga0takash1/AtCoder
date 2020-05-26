#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    long long a[n];
/*
    std::vector<long long> v;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        v.push_back(a[i]);
    }
*/
/*
    for (int i = 0; i < m; ++i) {
        sort(v.begin(), v.end());
        v[v.size()-1] /= 2;
    }
*/
/*
    make_heap(v.begin(),v.end());
    for(int i = 0 ; i < m; i++) {
        long long a=v.front();
        pop_heap(v.begin(),v.end());
        v.pop_back();
        a = a/2;
        v.push_back(a);
        push_heap(v.begin(),v.end());
    }
*/
    //cout << accumulate(v.begin(), v.end(), 0LL) << endl;

    priority_queue<long long> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        q.push(a[i]);
    }

    for (int i = 0; i < m; ++i) {
        long long a = q.top();
        q.pop();
        q.push(a/2);
    }
    long long ans = 0;
    while (!q.empty()) {
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
    return 0;
}
