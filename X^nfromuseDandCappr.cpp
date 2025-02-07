#include<iostream>
using namespace std;
double power(double x, int n) {
    if (n == 0) return 1; 
    double half = power(x, n / 2); 
    if (n % 2 == 0) {
        return half * half;
    } else {
        return x * half * half; 
    }
}
int main() {
    double x = 6.0;
    int n = 5;
    cout << "Result of " << x << "^" << n << " is: " << power(x, n) << endl;
    return 0;
}
