#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string input;

    for(int i = 0; i < 3; i++){
        cin >> input;
        if(input == "FizzBuzz"){
            continue;
        }
        if(input == "Fizz"){
            continue;
        }
        if(input == "Buzz"){
            continue;
        }
        else{
            int result = stoi(input);
            result += 3 - i;

            if(result % 15 == 0) {cout << "FizzBuzz"; break;}
            if(result % 3 == 0) {cout << "Fizz"; break;}
            if(result % 5 == 0) {cout << "Buzz"; break;}
            else {cout << result; break;}
        }
    }
}