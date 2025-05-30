#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    int bonus = n / 10;
    int cost = (n * 12000) + (k-bonus) * 2000; 
    return cost;
}