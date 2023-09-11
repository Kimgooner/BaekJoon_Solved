#include <iostream>
#include <vector>
#include <algorithm>

int N, input;
int player[21][21];
int ppl[21];
std::vector<int> res;

void dfs(int n, int ind){
    if(n == N/2){
        int start = 0, link = 0;
        for(int i = 1; i <= N; i++){
            for(int j = i+1; j <= N; j++){
                if(ppl[i] == 0 && ppl[j] == 0){
                    start += player[i][j] + player[j][i];
                }
                else if(ppl[i] == 1 && ppl[j] == 1){
                    link += player[i][j] + player[j][i];
                }
            }
        }
        int sum = start-link;
        if(sum < 0){
            res.push_back(-sum);
        }else res.push_back(sum);
    }
    else{
        for(int i = ind+1; i <= N; i++){
            ppl[i] = 1;
            dfs(n+1, i);
            ppl[i] = 0;
        }
    }  
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;

    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < N+1; j++){
            std::cin >> input;
            player[i][j] = input;
        }
    }
    dfs(0,0);

    std::sort(res.begin(), res.end());
    std::cout << res[0];
}