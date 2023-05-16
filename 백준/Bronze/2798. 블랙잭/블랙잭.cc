#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;

    int input;
    std::vector<int> cards;
    for(int i = 0; i < N; i++){
        std::cin >> input;
        cards.push_back(input);
    }
    std::sort(cards.begin(), cards.end());
    int remain;
    std::vector<int> result;
    for(int i = 0; i < N; i++){
        remain = M;
        remain -= cards[i];
        for(int j = i+1; j < N; j++){
            int tmp1 = remain;
            if(cards[j] >= tmp1) {
                break;
            }
            else{
                tmp1 -= cards[j];
                for(int k = j+1; k < N; k++){
                    int tmp2 = tmp1;
                    if(cards[k] > tmp2) {
                        break;
                    }
                    else {
                        tmp2 -= cards[k];
                        result.push_back(M - tmp2);
                    }
                }
            }
        }
    }
    std::sort(result.begin(), result.end());
    std::cout << *(result.end()-1);
}