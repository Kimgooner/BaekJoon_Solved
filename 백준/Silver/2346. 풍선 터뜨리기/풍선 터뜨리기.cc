#include <iostream>
#include <deque>

int N, input;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::deque<int> dq_num;
    std::deque<int> dq_ord;

    std::cin >> N;
    for(int i = 0; i < N; i++){
        std::cin >> input;
        dq_num.push_back(i+1);
        dq_ord.push_back(input);
    }

    int cur = dq_ord.front();
    dq_ord.pop_front();
    dq_num.pop_front();
    std::cout << 1 << " ";

    while(!dq_num.empty()){
        if(cur < 0){
            cur = cur * -1;
            for(int i = 0; i < cur-1; i++){
                dq_ord.push_front(dq_ord.back());
                dq_num.push_front(dq_num.back());
                dq_ord.pop_back();
                dq_num.pop_back();
            }
            std::cout << dq_num.back() << " ";
            cur = dq_ord.back();
            dq_ord.pop_back();
            dq_num.pop_back();
        }
        else {
            for(int i = 0; i < cur-1; i++){
                dq_ord.push_back(dq_ord.front());
                dq_num.push_back(dq_num.front());
                dq_ord.pop_front();
                dq_num.pop_front();
            }
            std::cout << dq_num.front() << " ";
            cur = dq_ord.front();
            dq_ord.pop_front();
            dq_num.pop_front();
        }
    }
}
