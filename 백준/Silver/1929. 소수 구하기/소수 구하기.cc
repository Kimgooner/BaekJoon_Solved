#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int first, last;
    std::cin >> first >> last;
    std::vector<int> num_list;

    for(int i = first; i <= last; i++){
        if(i != 1)
            num_list.push_back(i);
    }

    int idx = 2;
    while(idx <= sqrt(last)){
        for(int& v : num_list){
            if((v % idx == 0 && v != idx) && v != 0)
                v = 0;
        }
        idx++;
    }

    for(int v : num_list){
        if (v != 0)
            std::cout << v << "\n";
    }
}
