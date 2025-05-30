#include <string>
#include <vector>

using namespace std;

bool charCompare(int s, string str1, string str2){
    for(int i = s; i < s + str2.size(); i++){
        if(str1[i] != str2[i-s]) return false;
    }
    return true;
}

int solution(string str1, string str2) {
    for(int i = 0; i < str1.size(); i++){
        if(str1[i] == str2[0]){
            if(charCompare(i, str1, str2)) return 1;
        }
    }
    return 2;
}

