#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> dice;
    int input;

    for(int i = 0; i < 3; i++) {
        std::cin >> input;
        dice.push_back(input);
    }

    std::sort(dice.begin(), dice.end());

    if(dice[0] == dice[2])
        std::cout << 10000+(dice[0]*1000);
    else if(dice[0] == dice[1] && dice[1] != dice[2])
        std::cout << 1000+(dice[0]*100);
    else if(dice[0] != dice[1] && dice[1] == dice[2])
        std::cout << 1000+(dice[1]*100);
    else if(dice[0] != dice[1] && dice[1] != dice[2])
        std::cout << dice[2]*100;
}