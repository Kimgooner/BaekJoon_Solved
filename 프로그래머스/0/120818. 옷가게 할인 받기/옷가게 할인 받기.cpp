#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    int answer = 0;
    
    int discount = 0;
    if(price >= 100000) discount += 5;
    if(price >= 300000) discount += 5;
    if(price >= 500000) discount += 10;
    double result = price * ((100.0-discount)/100.0);
    
    return result;
}