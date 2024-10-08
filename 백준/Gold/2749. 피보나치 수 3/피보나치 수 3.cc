#include <iostream>
using namespace std;

long long N;
const int M = 1000000;
const int P = 1500000;
int arr[P];

int main(){
    cin >> N;

    if(N==0) cout << "0";
    else if(N==1) cout << "1";
    else{
        arr[0] = 0;
        arr[1] = 1;
        for(int i = 2; i < P; i++){
            arr[i] = (arr[i-1] + arr[i-2]) % M;
        }
        cout << arr[N%P];
    }
}