#include <iostream>

int hash_val[55];

int N;
std::string str;
int main(){
    std::cin >> N >> str;

    hash_val[0] = 1;
    hash_val[1] = 31;
    for(int i = 2; i < 51; i++){
        hash_val[i] = (hash_val[i-1] * 31) % 1234567891;
    }

    int sum = 0;
    int val;
    for(int i = 0; i < str.size(); i++){
        val = hash_val[i] * (str[i] - 'a' + 1);
        sum += val;
    }

    std::cout << sum % 1234567891;
}
