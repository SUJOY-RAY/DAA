#include <iostream>

using namespace std;

int power(int x, int n){
    if (n==0){
        return 1;
    }
    int half=power(x,n/2);
    return n%2==0?half*half:x*half*half;
}

int main(int argc, char const *argv[])
{
    cout<<power(2,3);
    return 0;
}
