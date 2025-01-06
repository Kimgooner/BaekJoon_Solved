#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

int N, M;
int visited[9];
int result[9];
vector<int> input;

void seq(int depth){
    if(depth == M){
        for(int i = 0; i < M; i++){
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    else{
        int last = 0;
        for(int i = 0; i < N; i++){
            if(visited[i] || last == input[i]) continue;
            visited[i] = 1;
            result[depth] = input[i];
            last = input[i];
            seq(depth+1);
            result[depth] = 0;
            visited[i] = 0;
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
    seq(0);
}