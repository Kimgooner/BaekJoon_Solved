#include <iostream>
#include <iomanip>

double factorial(int n){
    double ans = 1;
    for(int i = 1; i <= n; i++){
        ans *= i;
    }
    return ans;
}

int main() {
    int T;
    std::cin >> T;
    long long N, M;
    while(T--) {
        std::cin >> N >> M;
        double ans = factorial(M) / (factorial(M - N) * factorial(N));
        std::cout << std::fixed << std::setprecision(0);
        std::cout << ans << "\n";
    }
}