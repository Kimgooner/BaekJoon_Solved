#include <iostream>

int N;
int inputs[1005];
int rv, lv, result;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N;
    int num;
    for(int i = 0; i < N; i++){
        std::cin >> num;
        inputs[i] = num;
    }

    for(int i = 0; i < N; i++){
        rv = 0; lv = 0;
        int rdp[1005], ldp[1005];
        for(int s = 0; s < 1005; s++){
            rdp[s] = 0; ldp[s] = 0;
        }
        for(int j = 0; j < i; j++){
            if(inputs[j] < inputs[i]){
                int max = 0;
                int v = inputs[j];
                for(int k = 1; k < v; k++){
                    if(max < rdp[k]) max = rdp[k];
                }
                rdp[v] = max + 1;
                if(rv < rdp[v]) rv = rdp[v];
            }
        }
        for(int j = i+1; j < N; j++){
            if(inputs[j] < inputs[i]){
                int max = 0;
                int v = inputs[j];
                for(int k = v+1; k < 1001; k++){
                    if(max < ldp[k]) max = ldp[k];
                }
                ldp[v] = max + 1;
                if(lv < ldp[v]) lv = ldp[v];
            }
        }
        if(result < rv + lv + 1) result = rv + lv + 1;
    }
    std::cout << result;
}