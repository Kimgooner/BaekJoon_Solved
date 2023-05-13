#include <iostream>

int main() {
    std::string alpha, alpha_c;
    std::cin >> alpha;

    int cnt = 0;
    for(int i = 0; i < alpha.size(); i++){
        if(alpha[i] == 'c'){
            if(alpha[i+1] == '=' || alpha[i+1] == '-')
                i++;
        }
        else if(alpha[i] == 'd') {
            if(alpha[i+1] == '-')
                i++;
            else if(alpha[i+1] == 'z' && alpha[i+2] == '=')
                i += 2;
        }
        else if((alpha[i] == 'l' || alpha[i] == 'n') && alpha[i+1] == 'j')
            i++;
        else if((alpha[i] == 's' || alpha[i] == 'z') && alpha[i+1] == '=')
            i++;
        cnt++;
    }
    std::cout << cnt;
}