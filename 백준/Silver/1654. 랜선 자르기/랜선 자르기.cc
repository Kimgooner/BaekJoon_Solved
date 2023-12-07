#include <iostream>
#include <vector>

int K, N;
std::vector<int> wires;

bool check(long long mid){
    long long sum = 0;
    for(int length : wires){
        sum += (length / mid);
    }
    if(sum >= N) return true;
    else return false;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> K >> N;
    int lanLength;
    while(K--){
        std::cin >> lanLength;
        wires.push_back(lanLength);
    }
    long long start = 1;
    long long end = 2147483647;
    while(start <= end){
        long long mid = (start + end) / 2;
        if(check(mid)){
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    std::cout << end;
}