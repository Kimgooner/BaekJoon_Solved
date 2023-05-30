#include <iostream>

int N, M;
int nums[9] = {0, };
bool check[9] = {0, };

void find(int n, int start){
    if(n == M) {
        for (int i = 0; i < M; i++) {
            std::cout << nums[i] << " ";
        }
        std::cout << "\n";
    }
    else {
        for(int i = start+1; i <= N; i++){
            if(!check[i]) {
                check[i] = true;
                nums[n] = i;
                find(n+1, i);
                check[i] = false;
            }
        }
    }
}

int main() {
    std::cin >> N >> M;
    find(0, 0);
}