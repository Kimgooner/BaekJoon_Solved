#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int T, P;
int inputs[6];

int main() {
    cin >> N;

    int result = 0;
    for(int i = 0; i < 6; i++){
        cin >> inputs[i];
    }
    cin >> T >> P;

    for(int i = 0; i < 6; i++){
        int input = inputs[i];
        if(input % T == 0) result += input/T;
        else result += input/T + 1;
    }

    cout << result << "\n";
    cout << N / P << " " << N % P;


}