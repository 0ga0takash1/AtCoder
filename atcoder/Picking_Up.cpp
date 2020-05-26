#include <bits/stdc++.h>
using namespace std;

static int minElement(const int* array, size_t size)
{
    size_t i;
    int min;

    assert(array != NULL);
    assert(size >= 1);

    min = array[0];
    for (i = 1; i < size; ++i) {
        if (min > array[i]) {
            min = array[i];
        }
    }

    return min;
}

int main(){
    int n;cin >> n;
    int x[50],y[50],ans[100000];
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        ans[i] = 1;
    }

    int a = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; i < n; j++) {
            int p = x[j] - x[i];
            int q = y[j] - y[i];

            for (int k = 1; k < n; k++) {
                if ( abs(x[k] - x[k-1]) == abs(p) && abs( y[k] - y[k-1] ) == abs(q) ) {

                } else {
                    ans[a]++;
                }
            }
            a++;
        }
    }

    cout << minElement(ans, a) << endl;
}
