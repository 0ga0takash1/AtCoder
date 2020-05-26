#include <iostream>
using namespace std;

int main() {
    int a,b,c,k;
    int d = 0;
    std::cin >> a >> b >> k;
    for(int i = 1;i < 100;i++){
        if( a % i == 0
            && b % i == 0 ){
                c = i;
                d++;
            }
        if(d == k) break;
    }
    std::cout << c << std::endl;
}
