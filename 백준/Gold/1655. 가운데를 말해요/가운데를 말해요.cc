#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int,vector<int>> max_heap;
priority_queue<int,vector<int>,greater<>> min_heap;

bool comp(int val){
    return max_heap.top() >= val;
}

void change(){
    max_heap.push(min_heap.top());
    min_heap.pop();
}

void change_2(){
    min_heap.push(max_heap.top());
    max_heap.pop();
}

int N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int input;
    cin >> input;
    cout << input << "\n";

    max_heap.push(input);
    N--;

    while (N--){
        cin >> input;
        if(comp(input)){
            max_heap.push(input);
        }
        else{
            min_heap.push(input);
        }
        if(min_heap.size() > max_heap.size()){
            change();
        }
        if(max_heap.size() > min_heap.size()+1) {
            change_2();
        }

        cout << max_heap.top() << "\n";
    }
}