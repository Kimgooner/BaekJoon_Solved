#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<int, vector<int>, greater<>> pq;
    int N;
    cin >> N;
    int a;

    while(N--){
        cin >> a;
        if(a != 0) pq.push(a);
        else {
            if (pq.empty()) cout << 0 << "\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}