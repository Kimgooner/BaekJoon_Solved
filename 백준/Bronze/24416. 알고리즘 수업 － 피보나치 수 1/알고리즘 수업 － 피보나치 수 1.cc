#include <iostream>

int cnt1 = 0, cnt2 = 0;
int f[41];

int fib(int n) {
        if (n == 1 || n == 2) {cnt1++; return 1;}
        else return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {
        f[1] = 1;
        f[2] = 1;
        for (int i = 3; i <= n; i++) {
            f[i] = f[i-1] + f[i-2];
            cnt2++;
        }
        return f[n];
}


int main() {
    int N;
    std::cin >> N;
    fib(N);
    fibonacci(N);

    std::cout << cnt1 << " " << cnt2;
}