#include <iostream>
#include <cmath>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    bool isQuit = false;
    int a,b,c;
    while (!isQuit){
        std::cin >> a >> b >> c;
        if(a==0) isQuit = true;
        else{
            int max = std::max(a, std::max(b,c));
            int others = 0;
            if(max != a) others += pow(a,2);
            if(max != b) others += pow(b,2);
            if(max != c) others += pow(c,2);

            if(pow(max,2) == others) std::cout << "right";
            else std::cout << "wrong";
            std::cout << "\n";
        }
    }
}