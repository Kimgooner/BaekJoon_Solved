#include <iostream>
#include <vector>
using namespace std;
int graph[11][3];
int N;
int sum = 0;

int dfs(int n, int std) {
    if(n == std) {sum++; return 0;}
    else {
        for (int i = 0; i < 3; i++) {
            if (n + graph[n][i] <= std) {
                dfs(n + graph[n][i], std);
            }
        }
    }
    return 0;
}

int main(){
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 3; j++){
            graph[i][j] = j+1;
        }
    }

    cin >> N;
    vector<int> nums;
    int num;
    for(int i = 0; i < N; i++){
        cin >> num;
        nums.push_back(num);
    }

    for(int i = 0; i < N; i++){
        sum = 0;
        dfs(0, nums[i]);
        cout << sum << "\n";
    }
}