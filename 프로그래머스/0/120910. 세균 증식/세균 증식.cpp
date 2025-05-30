#include <string>
#include <vector>

using namespace std;

int solution(int n, int t) {
    int answer = 0;
    
    while(t--){
        n *= 2;
    }
    
    return n;
}