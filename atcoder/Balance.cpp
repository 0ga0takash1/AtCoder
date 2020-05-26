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
    int n,w[100],c[100],ans;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    for (int i = 1; i <= n; i++){
        int s1 = 0;
        int s2 = 0;
        for (int j = 0; j < n; j++) {
            if ( j <= i) {
                s1 += w[j];
            } else {
                s2 += w[j];
            }
        }
        c[i-1] = abs(s1-s2);
        cout << s1 << " " << s2 << " " << c[i-1] << endl;
    }

    cout << minElement(c, n) << endl;
}
