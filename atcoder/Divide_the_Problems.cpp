#include <bits/stdc++.h>
using namespace std;

int q_sort(long long numbers[], int left, int right, int pivot)
{
    int l_hold, r_hold;

    l_hold = left;
    r_hold = right;
    while (left < right)
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            numbers[left] = numbers[right];
            left++;
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++;
        if (left != right)
        {
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    left = (pivot-1)-left;
    right = right-pivot-1;

    if ( left == right ) {
        return 1;
    }
    return 0;
}

static int maxElement(const long long* array, size_t size)
{
    size_t i;
    int max;

    assert(array != NULL);
    assert(size >= 1);

    max = array[0];
    for (i = 1; i < size; ++i) {
        if (max < array[i]) {
            max = array[i];
        }
    }

    return max;
}

int main(){
    int n;
    cin >> n;
    long long d[n];
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    long long ans = 0;
    for (int i = 0; i < maxElement(d, n); i++) {
        if ( q_sort(d, 0, n, i) == 1) {
            ans++;
        }
    }

    cout << ans << endl;
}
