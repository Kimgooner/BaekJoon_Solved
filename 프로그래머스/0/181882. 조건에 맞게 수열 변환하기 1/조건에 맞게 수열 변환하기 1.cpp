#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for(int i : arr){
        if(i >= 50 && i % 2 == 0) answer.push_back(i / 2);
        else if (i < 50 && i % 2 == 1) answer.push_back(i * 2);
        else answer.push_back(i);
    }
    
    return answer;
}