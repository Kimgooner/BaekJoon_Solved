#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::queue<int> q;
    int N, K;
    std::cin >> N >> K;

    int num = 1;
    while(N--) {
        q.push(num++);
    }

    std::vector<int> result;
    while(!q.empty()){
        for(int i = 0; i < K-1; i++){
            q.push(q.front());
            q.pop();
        }
        result.push_back(q.front());
        q.pop();
    }
    std::cout << "<";
    for(int i = 0; i < result.size()-1; i++){
        std::cout << result[i] << ", ";
    }
    std::cout << *(result.end()-1) << ">";
}