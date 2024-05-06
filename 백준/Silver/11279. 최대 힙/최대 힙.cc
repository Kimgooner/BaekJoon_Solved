#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    priority_queue<int, vector<int>> pq;
    while(N--){
        int cmd;
        cin >> cmd;
        switch (cmd) {
            case 0:
                if(pq.empty()){
                    cout << 0 << "\n";
                }
                else{
                    cout << pq.top() << "\n";
                    pq.pop();
                }
                break;
            default:
                pq.push(cmd);
                break;
        }
    }
}