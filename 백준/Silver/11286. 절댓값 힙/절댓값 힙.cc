#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct cmp{
    bool operator()(const int x1, const int x2){
        if(abs(x1) > abs(x2)) return true;
        else if(abs(x1) == abs(x2)){
            if(x1 > x2) return true;
            else return false;
        }
        else return false;
    }
};

priority_queue<int, vector<int>, cmp> abs_heap;
int N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    int input;
    while(N--){
        cin >> input;
        if(input == 0){
            if(abs_heap.empty()) cout << "0\n";
            else {
                cout << abs_heap.top() << "\n";
                abs_heap.pop();
            }
        }
        else{
            abs_heap.push(input);
        }
    }
}
