#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    while(N--) {
        int A, B;
        std::cin >> A >> B;
        int low_num;
        if (A > B)
            low_num = B;
        else
            low_num = A;

        int max_div;
        for (int i = 1; i <= low_num; i++) {
            if (B % i == 0 && A % i == 0)
                max_div = i;
        }
        std::cout << (A*B)/max_div << "\n";
    }
}