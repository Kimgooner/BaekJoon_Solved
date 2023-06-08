#include <iostream>
#include <vector>
#include <algorithm>

int N;
int nums[100];
int op[4];
int sum = 0;
std::vector<int> result;
int r, l;

int calc(int a, int b, int ops){
    if(ops == 0) return a+b;
    else if(ops == 1) return a-b;
    else if(ops == 2) return a*b;
    else return a/b;
}


void dfs(int n) {
    if(n == sum) result.push_back(r);
    else {
        if(n == 0){
            r = nums[0];
            l = nums[1];
        }
        for(int i = 0; i < 4; i++){
            if(op[i] != 0){
                int tmp1, tmp2;
                tmp1 = r; tmp2 = l;
                r = calc(r, l, i);
                l = nums[n+2];
                op[i]--;
                dfs(n+1);
                op[i]++;
                r = tmp1;
                l = tmp2;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++){
        std::cin >> nums[i];
    }
    for(int& v : op){
        std::cin >> v;
        sum += v;
    }

    dfs(0);

    std::sort(result.begin(), result.end());
    std::cout << *(result.end()-1) << "\n" << *(result.begin());
}