#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d;
    int Answer = 0;
    std::cin >> a >> b;
    std::cin >> c >> d;
    Answer = ( a*b ) - ( a*d ) - ( b*c ) + ( c*d );

    std::cout << Answer << std::endl;
}
