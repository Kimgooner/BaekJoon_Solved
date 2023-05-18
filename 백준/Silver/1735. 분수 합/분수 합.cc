#include <iostream>

int Euclidean(int a, int b){
    int r = a % b;
    if(r == 0) {
        return b;
    }
    return Euclidean(b, r);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int A_up, A_down;
    int B_up, B_down;
    std::cin >> A_up >> A_down;
    std::cin >> B_up >> B_down;
    int max_div = Euclidean(A_down, B_down);
    int result_down = (A_down*B_down)/max_div;
    int A_mul = result_down/A_down;
    int B_mul = result_down/B_down;
    int result_up = (A_up*A_mul) +( B_up*B_mul);
    
    int max_div2 = Euclidean(result_up, result_down);
    result_up = result_up / max_div2;
    result_down = result_down / max_div2;
    std::cout << result_up << " " << result_down;

}