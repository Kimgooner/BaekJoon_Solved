#include <string>
#include <vector>

using namespace std;

char lowerChar(char c){
    if(c >= 'A' && c <= 'Z') return c - 'A' + 'a';
    else return c;
}

int solution(string myString, string pat) {
    int answer = 0;
    
    if(pat.size() > myString.size()) return 0;
    else{
        for(int i = 0; i < myString.size() - pat.size()+1; i++){
            if(lowerChar(myString[i]) == lowerChar(pat[0])){
                for(int j = 0; j < pat.size(); j++){
                    if(lowerChar(myString[i+j]) != lowerChar(pat[j])) break;
                    if(j == pat.size()-1) return 1;
                }
            }   
        }
    }
    return 0;
}