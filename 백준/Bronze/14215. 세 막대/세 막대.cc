#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int input;
    std::vector<int> line_set;

    for(int i = 0; i < 3; i++){
        std::cin >> input;
        line_set.push_back(input);
    }
    std::sort(line_set.begin(), line_set.end());

    for(int i = line_set[2]; i > 0; i--){
        if(line_set[0] + line_set[1] > i) {
            std::cout << line_set[0] + line_set[1] + i;
            break;
        }
    }
}
