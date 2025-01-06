#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<int> numbers;

int visited[10001];
int result[10];

void dfs(int depth){
    if(depth == M-1){
        for(int i = 0; i < M; i++){
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    for(int i = 0; i < N; i++){
        if(visited[numbers[i]]) continue;
        result[depth+1] = numbers[i];
        visited[numbers[i]] = 1;
        dfs(depth+1);
        visited[numbers[i]] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;

    int input;
    for(int i = 0; i < N; i++){
        cin >> input;
        numbers.push_back(input);
    }
    sort(numbers.begin(), numbers.end());

    for(int i = 0; i < N; i++){
        fill_n(visited, 10001, 0);
        fill_n(result, 10, 0);

        visited[numbers[i]] = 1;
        result[0] = numbers[i];

        dfs(0);
    }
}