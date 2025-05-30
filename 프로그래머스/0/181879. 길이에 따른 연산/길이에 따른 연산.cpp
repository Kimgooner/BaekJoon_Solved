#include <string>
#include <vector>

using namespace std;

int getPlus(vector<int> num_list){
    int result = 0;
    for(int i : num_list){
        result += i;
    }
    return result;
}

int getMul(vector<int> num_list){
    int result = 1;
    for(int i : num_list){
        result *= i;
    }
    return result;
}

int solution(vector<int> num_list) {
    if(num_list.size() >= 11) return getPlus(num_list);
    else return getMul(num_list);
}