#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int N, M;
string S;
string prev_list = "IO";

bool find_str(int n, int idx, int prev){
    if(n > (2*N)+1) return true;
    if(idx >= M) return false;
    if(prev_list[prev] != S[idx]) return find_str(n+1, idx+1, (prev+1)%2);
    return false;
}

int main(){
    cin >> N >> M >> S;
    int size = M;

    int cnt = 0;
    for(int i = 0; i < M; i++){
        if(S[i] == 'I') {
            if(find_str(2, i + 1, 0)) cnt++;
        }
    }
    cout << cnt;
}