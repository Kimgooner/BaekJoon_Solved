#include <iostream>

int N;
long long arr[101][10];
long long div_v = 1000000000;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N;
    for (int i = 1; i <= 9; i++) {
        arr[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) {
                arr[i][j] = arr[i - 1][1];
            } else if (j == 9) {
                arr[i][j] = arr[i - 1][8];
            } else {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];
            }
            arr[i][j] = arr[i][j] % div_v;
        }
    }

    long long sum = 0;
    for (int i = 0; i <= 9; i++) {
        sum += arr[N][i];
        sum = sum % div_v;
    }

    std::cout << sum;
}