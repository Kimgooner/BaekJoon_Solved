#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    string del = "aeiou";
    
    for(char c1 : my_string){
        bool isFind = false;
        for(char c2 : del){
            if(c1 == c2){
                isFind = true;
                break;
            }
        }
        if(!isFind) answer+= c1;
    }
    
    return answer;
}