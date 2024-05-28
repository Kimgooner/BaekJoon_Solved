#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T, N, sz;

int diff(string s1, string s2){
    int val = 0;
    for(int i = 0; i < 4; i++){
        if(s1[i] != s2[i]){
            val++;
        }
    }
    return val;
}

vector<vector<int>> combination3(int size){
    vector<vector<int>> result;
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            for(int k = j+1; k < size; k++){
                vector<int> buf = {i,j,k};
                result.push_back(buf);
            }
        }
    }
    return result;
}

int main(){
    cin >> T;
    while (T--){
        cin >> N;
        vector<string> mbti;
        string s;
        for(int l = 0; l < N; l++){
            cin >> s;
            mbti.push_back(s);
        }
        if(N > 32) cout << 0 << "\n";
        else {
            sz = mbti.size();
            vector<vector<int>> idx = combination3(sz);
            vector<int> res;
            for (vector<int> v: idx) {
                int sum = 0;
                sum += diff(mbti[v[0]], mbti[v[1]]);
                sum += diff(mbti[v[0]], mbti[v[2]]);
                sum += diff(mbti[v[1]], mbti[v[2]]);
                res.push_back(sum);
            }
            sort(res.begin(), res.end());
            cout << res[0] << "\n";
        }
    }
}