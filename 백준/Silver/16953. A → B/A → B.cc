#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int A, B;
queue<int> q;
bool isFind = false;

int fun1(int a){
    return a/2;
}

int fun2(int a){
    return (a-1)/10;
}

void bfs(int count){
    queue<int> buffer;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(cur == A){
            isFind = true;
            break;
        }

        if(cur % 2 == 0 && cur != 0){
            buffer.push(fun1(cur));
        }

        if(cur % 10 == 1 && cur > 10){
            buffer.push(fun2(cur));
        }
    }
    while(!buffer.empty()){
        q.push(buffer.front());
        buffer.pop();
    }
    if(isFind){
        cout << count + 1;
        return;
    }
    if(!q.empty()) bfs(count+1);
}

int main(){
    cin >> A >> B;
    q.push(B);

    bfs(0);
    if(!isFind) cout << -1;
}