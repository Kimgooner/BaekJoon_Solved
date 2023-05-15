#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int input;
    while(true){
        std::vector<int> line_set;
        for(int i = 0; i < 3; i++){
            std::cin >> input;
            line_set.push_back(input);
        }
        std::sort(line_set.begin(), line_set.end());
        if(line_set[0] == 0 && line_set[0] == line_set[2])
            break;
        else if(line_set[0] + line_set[1] <= line_set[2])
            std::cout << "Invalid\n";
        else if(line_set[0 ] != 0 && line_set[0] == line_set[2])
            std::cout << "Equilateral\n";
        else if(line_set[0] != line_set[1] && line_set[1] != line_set[2])
            std::cout << "Scalene\n";
        else
            std::cout << "Isosceles\n";
    }
}