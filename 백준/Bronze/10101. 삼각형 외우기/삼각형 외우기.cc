#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int angle, sum = 0;
    std::vector<int> angle_set;
    for(int i = 0; i < 3; i++){
        std::cin >> angle;
        angle_set.push_back(angle);
        sum += angle;
    }
    if(sum != 180)
        std::cout << "Error";
    else {
        std::sort(angle_set.begin(), angle_set.end());
        if(angle_set[0] == angle_set[1] && angle_set[1] == angle_set[2])
            std::cout << "Equilateral";
        else if(angle_set[0] != angle_set[1] && angle_set[1] != angle_set[2])
            std::cout << "Scalene";
        else
            std::cout << "Isosceles";
    }
}