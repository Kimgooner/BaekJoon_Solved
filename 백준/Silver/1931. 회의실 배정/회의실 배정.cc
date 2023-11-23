#include <iostream>
#include <vector>
#include <algorithm>

int N;

bool cmp(std::pair<int,int> p1, std::pair<int,int> p2){
    if (p1.second < p2.second) return true;
    else if(p1.second == p2.second){
        if(p1.first < p2.first) return true;
        else return false;
    }
    else return false;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N;

    int a, b;
    std::vector<std::pair<int,int>> meetings;

    for(int i = 0; i < N; i++){
        std::cin >> a >> b;
        meetings.emplace_back(a,b);
    }
    std::sort(meetings.begin(), meetings.end(), cmp);

    int cur = 0, cnt = 0;
    for(std::pair<int,int> p : meetings){
        if(p.first >= cur) {cur = p.second; cnt++;}
    }
    std::cout << cnt;
}