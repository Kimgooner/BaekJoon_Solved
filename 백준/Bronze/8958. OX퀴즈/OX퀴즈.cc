#include <iostream>

int N;
int main(){
    std::cin >> N;

    std::string result;
    for(int i = 0; i < N; i++){
        std::cin >> result;

        int buf = 0;
        int score = 0;
        for(char c : result){
            if(c == 'O'){
                score += ++buf;
            }
            else{
                buf = 0;
            }
        }
        std::cout << score << "\n";
    }
}