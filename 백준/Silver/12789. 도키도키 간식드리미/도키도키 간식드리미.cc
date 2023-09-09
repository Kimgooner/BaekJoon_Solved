#include <iostream>
#include <stack>
#include <deque>

int N, input;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    std::deque<int> dq;
    std::stack<int> st;

    for(int i = 0; i < N; i++){
        std::cin >> input;
        dq.push_back(input);
    }

    int id = 1;
    bool chk = true;
    for(int i = 0; i < N; i++){

        while(true) {
            if (dq.front() == id) {
                dq.pop_front();
                id++;
                break;
            } else if (st.empty() && dq.front() != id) {
                if(dq.empty()){ chk = false; break; }
                else{
                    st.push(dq.front());
                    dq.pop_front();
                }
            } else if (!st.empty() && dq.front() != id) {
                if (st.top() != id) {
                    if(dq.empty()){ chk = false; break; }
                    else{
                        st.push(dq.front());
                        dq.pop_front();
                    }
                } else {
                    st.pop();
                    id++;
                    break;
                }
            }
        }
    }

    if(chk)
        std::cout << "Nice";
    else
        std::cout << "Sad";
}