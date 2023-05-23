#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

bool cmp(int a, int b){
    if(a > b) return true;
    else return false;
}

int main() {
    int T;
    std::cin >> T;

    int N, M, K;
    while(T--) {
        std::vector<int> orders;
        std::queue<int> q;
        int cur_order;
        std::cin >> N >> M;
        for (int i = 0; i < N; i++) {
            std::cin >> K;
            orders.push_back(K);
            if (i == M) {
                cur_order = K;
                q.push(-1);
            }
            else
                q.push(K);
        }
        std::sort(orders.begin(), orders.end(), cmp);
        int idx = 0;
        while(true){
            if(q.front() == -1){
                if(cur_order == orders[idx]) {
                    std::cout << idx+1 << "\n";
                    break;
                }
                else{
                    q.push(q.front());
                    q.pop();
                }
            }
            else{
                if(q.front() == orders[idx]){
                    q.pop();
                    idx++;
                }
                else{
                    q.push(q.front());
                    q.pop();
                }
            }
        }
    }
}