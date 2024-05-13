#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int N, M;
string S;
int cnt = 0;
int fail[1000005];
int result[1000005];

char pattern(int i){
    if(i%2 == 0) return 'I';
    else return 'O';
}

void getFail(){
    for(int i = 1,j = 0; i < (2*N)+1; i++){
        while (j > 0 && pattern(i) != pattern(j)){
            j = fail[j-1];
        }
        if(pattern(i) == pattern(j)){
            fail[i] = ++j;
        }
    }
}

void KMP(){
    for(int i = 0,j = 0; i < M; i++){
        while (j > 0 && S[i] != pattern(j)){
            j = fail[j-1];
        }
        if(S[i] == pattern(j)){
            if(j == 2*N){
                j = fail[j];
                cnt++;
            }
            else{
                j++;
            }
        }
    }
}

int main() {
    cin >> N >> M >> S;
    getFail();
    KMP();
    cout << cnt;
}