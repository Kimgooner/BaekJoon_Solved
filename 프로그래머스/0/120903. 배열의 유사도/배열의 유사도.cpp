#include <string>
#include <vector>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    
    for(string a : s1){
        for(string b : s2){
            if(a == b) answer++;
        }
    }
    
    return answer;
}