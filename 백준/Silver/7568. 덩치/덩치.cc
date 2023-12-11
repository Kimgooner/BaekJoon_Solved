#include <iostream>
#include <vector>

bool comp(std::pair<int,int> p1, std::pair<int,int> p2){
    if(p1.first > p2.first && p1.second > p2.second) return true;
    else return false;
}

std::vector<std::pair<int,int>> buf;
int N, x, y;

int main(){
    std::cin >> N;
    while(N--){
        std::cin >> x >> y;
        buf.emplace_back(x,y);
    }

    std::vector<int> res;
    for(std::pair<int,int> p1 : buf){
        int val = 1;
        for(std::pair<int,int> p2 : buf){
            if(comp(p2, p1)) val++;
        }
        res.push_back(val);
    }

    for(int v : res){
        std::cout << v << " ";
    }
}