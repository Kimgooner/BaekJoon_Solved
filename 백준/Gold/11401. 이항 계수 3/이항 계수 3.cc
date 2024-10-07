#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

#define MOD 1000000007

using namespace std;
long long temp;

long long power(long long a, long long m){
    if ( m == 0 ) return 1;

    temp = power ( a , m /2) % MOD;
    if ( m % 2 == 1) return temp * temp % MOD * a % MOD;
    return temp * temp % MOD;
}

void cal(int n, int k){
    long long A = 1, B = 1, result;
    for(int i = n; i >= n - k + 1; i--) A = (A * i) % MOD;
    for(int i = 1; i <= k; i++) B = (B * i) % MOD;
    result = ((A % MOD) * power(B, MOD - 2) % MOD) % MOD;
    cout << result;
}

int main(){
    int n, k;
    cin >> n >> k;
    cal(n, k);
}
