#include <iostream>

int N, val;
std::string input;
int set = 0;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++){
        std::cin >> input;
        if(input == "add"){
            std::cin >> val;
            if((set & (1<<val)) == 0){
                set = set | (1<<val);
            }
        }
        else if(input == "remove"){
            std::cin >> val;
            if((set & (1<<val)) != 0){
                set = set ^ (1<<val);
            }
        }
        else if(input == "check"){
            std::cin >> val;
            if((set & (1<<val)) != 0){
                std::cout << 1 << "\n";
            }
            else std::cout << 0 << "\n";
        }
        else if(input == "toggle"){
            std::cin >> val;
            if((set & (1<<val)) == 0){
                set = set | (1<<val);
            }
            else
                set = set ^ (1<<val);
        }
        else if(input == "all"){
            set = 2097151;
        }
        else if(input == "empty"){
            set = 0;
        }
    }
}
