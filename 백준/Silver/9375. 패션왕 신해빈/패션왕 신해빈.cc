#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;

int main(){
    cin >> N;
    while(N--){
        int cnt;
        cin >> cnt;
        vector<pair<vector<string>, string>> drawer;
        while (cnt--){
            string clothes, kind;
            cin >> clothes >> kind;
            bool isFind = false;
            for(pair<vector<string>, string> &p : drawer){
                if(p.second == kind){
                    p.first.push_back(clothes);
                    isFind = true;
                }
            }
            if(!isFind){
                vector<string> nv;
                nv.push_back(clothes);
                drawer.emplace_back(nv,kind);
            }
        }
        int result = 1;
        for(pair<vector<string>, string> &p : drawer){
            result *= (p.first.size() + 1);
        }
        cout << result - 1 << "\n";
    }
}