#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
int T;

int euclidean(int a, int b){
    int r = a % b;
    if(r == 0) return b;
    return euclidean(b, r);
}

int LCM(int a, int b){
    return (a*b) / euclidean(a,b);
}

int findDate(int M, int N, int x, int y){
    int limit = LCM(M,N);
    int mul = 0;

    while(x + (mul*M) <= limit){
        if((x + (mul*M)) % N == y) return x + (mul*M);
        if(N == y && (x + (mul*M)) % N == 0) return x + (mul*M);
        mul += 1;
        //cout << (x + (mul*M)) % M << ", " << (x + (mul*M)) % N << "\n";
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    int M, N, x, y;

    while(T--){
        cin >> M >> N >> x >> y;
        cout << findDate(M,N,x,y) << "\n";
    }
}