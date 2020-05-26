#include <bits/stdc++.h>
using namespace std;

static int minElement(const int* array, size_t size)
{
    size_t i;
    int min,num;

    assert(array != NULL);
    assert(size >= 1);

    min = array[0];
    for (i = 1; i < size; ++i) {
        if (min > array[i]) {
            min = array[i];
            num = i;
        }
    }

    return num;
}

int main(){
    int n, l;
    cin >> n >> l;

    int sum = 0;
    int taste[200], taste2[200];
    int h, ans;
    for (int i = 1; i <= n; i++) {
        sum += (l+i-1);
        taste[i-1] = l+i-1;
    }
    //h = sum/n;
    for (int i = 0; i < n; i++) {
        taste2[i] = abs(taste[i]);
    }
/*
    for (int i = 1; i <= n; i++) {
        if ( (l+i-1) == h ) {
            ans = i;
            break;
        }
    }
*/
    ans = sum - (l+minElement(taste2, n));
    cout << ans << endl;
}
