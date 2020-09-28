#include <cstdio>
#include <iostream>
using namespace std;
#include "basic.h"

int main(){

#ifdef _WIN32
    printf("This is not supported for Windows\n");
#endif

#ifdef __unix__
    Integer A(10, 123), B(11, 12);
    cout << "A = "<< A << endl;
    cout << "B = "<< B << endl;
    cout << "A+B = "<< A+B << endl;
#endif

    return 0;
}
