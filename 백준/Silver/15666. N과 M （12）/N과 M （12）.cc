#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

int N, M;
int result[9];
vector<int> input;

void seq(int depth, int pos){
    if(depth == M){
        for(int i = 0; i < M; i++){
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    else{
        int last = 0;
        for(int i = pos; i < N; i++){
            if(last == input[i]) continue;
            result[depth] = input[i];
            last = input[i];
            seq(depth+1, i);
            result[depth] = 0;
        }
    }
}

int main(){
    cin >> N >> M;

    int p;
    for(int i = 0; i < N; i++){
        cin >> p;
        input.push_back(p);
    }
    sort(input.begin(), input.end());
    seq(0, 0);
}