#include <iostream>
#include <deque>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::deque<int> dq;
    std::vector<int> order;

    int N, M;
    std::cin >> N >> M;

    int num = 1;
    for(int i = 0; i < N; i++){
        dq.push_back(num++);
    }

    int input;
    for(int i = 0; i < M; i++){
        std::cin >> input;
        order.push_back(input);
    }

    std::deque<int> dq_front;
    std::deque<int> dq_back;
    int sum = 0;
    int idx = 0;
    dq_front = dq;
    dq_back = dq;
    while(idx != M){
        int front_cnt = 0;
        int back_cnt = 0;
        while(true){
            if(dq_front.front() == order[idx]) {
                dq_front.pop_front();
                break;
            }
            else {
                dq_front.push_back(dq_front.front());
                dq_front.pop_front();
                front_cnt++;
            }
        }

        while(true){
            if(dq_back.front() == order[idx]) {
                dq_back.pop_front();
                break;
            }
            else {
                dq_back.push_front(dq_back.back());
                dq_back.pop_back();
                back_cnt++;
            }
        }
        if(front_cnt > back_cnt) {
            sum += back_cnt;
            dq_front = dq_back;
        }
        else{
            sum += front_cnt;
            dq_back = dq_front;
        }
        idx++;
    }
    std::cout << sum;
}