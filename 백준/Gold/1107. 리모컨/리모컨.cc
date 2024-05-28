#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int string_size;
vector<pair<int,int>> result;
int broken[10];

int toInt(char c){
    return c - '0';
}

bool cmp(pair<int,int> p1, pair<int,int> p2){
    if(p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
}

void dfs(int n, string s, int len){
    if(n == len+1){
        result.emplace_back(abs(N-stoi(s)), len);
        return;
    }
    for(int i = 0; i <= 9; i++){
        if(!broken[i]){
            if(n == 1 && i == 0 && len > 1) continue;
            s += (i+'0');
            dfs(n+1, s, len);
            s.pop_back();
        }
    }
}

int main() {
    cin >> N >> M;
    int button;
    while (M--) {
        cin >> button;
        broken[button] = 1;
    }

    int base = abs(N - 100);

    string target = to_string(N);
    string_size = target.size();
    for(int i = 1; i <= 6; i++){
        string buf = "";
        dfs(1,buf,i);
    }
    if (result.empty()) cout << base;
    else {
        sort(result.begin(), result.end(), cmp);
        cout << min(result[0].first + result[0].second, base);
    }
}