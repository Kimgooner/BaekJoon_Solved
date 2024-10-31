#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int N, cnt;
int dp[21][21][21];
int dest[21];

/*
 * dp[3][2][5] = 0;
 * dp[3][3][5] = 1;
 * dp[3]
 */
int next(int idx, int o1, int o2){
    if(idx == cnt+1) return 0;
    if(dp[idx][o1][o2] != -1){
        return dp[idx][o1][o2];
    }
    int nextBlock = dest[idx];
    dp[idx][o1][o2] = min(abs(o1 - nextBlock) + next(idx+1, nextBlock, o2), abs(o2 - nextBlock) + next(idx+1, o1, nextBlock));
    return dp[idx][o1][o2];
}

int main(){
    cin >> N;

    int o1, o2;
    cin >> o1 >> o2;
    cin >> cnt;

    int input;
    for(int i = 1; i <= cnt; i++){
        cin >> input;
        dest[i] = input;
    }

    memset(dp, -1, sizeof(dp));
    cout << next(1, o1, o2);
}