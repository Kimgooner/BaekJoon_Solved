#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define mod 10000

using namespace std;
int reg[4];
int visited[10000];

int reg2num(){
    return reg[0] * 1000 + reg[1] * 100 + reg[2] * 10 + reg[3];
}

void num2reg(int num){
    reg[0] = num / 1000;
    reg[1] = (num % 1000) / 100;
    reg[2] = (num % 100) / 10;
    reg[3] = (num % 10);
}

void func_D(){
    int buf = reg2num();
    num2reg((2 * buf) % mod);
}

void func_S(){
    int buf = reg2num();
    if (buf == 0) num2reg(9999);
    else num2reg(buf-1);
}

void func_L(){
    int buf = reg[0];
    reg[0] = reg[1];
    reg[1] = reg[2];
    reg[2] = reg[3];
    reg[3] = buf;
}

void func_R(){
    int buf = reg[3];
    reg[3] = reg[2];
    reg[2] = reg[1];
    reg[1] = reg[0];
    reg[0] = buf;
}

string getResult(int ans){
    fill_n(visited, 10000, 0);
    queue<pair<string,int>> q;
    q.emplace("",reg2num());

    visited[reg2num()] = 1;

    int max = 10000;
    while(max--){
        pair<string,int> cur = q.front();
        if(cur.second == ans) return cur.first;
        q.pop();
        int buf = cur.second;
        string str = cur.first;

        num2reg(buf);
        str = cur.first;
        func_D();
        if(visited[reg2num()] == 0) {
            q.emplace(str.append("D"), reg2num());
            visited[reg2num()] = 1;
        }

        num2reg(buf);
        str = cur.first;
        func_L();
        if(visited[reg2num()] == 0) {
            q.emplace(str.append("L"), reg2num());
            visited[reg2num()] = 1;
        }

        num2reg(buf);
        str = cur.first;
        func_R();
        if(visited[reg2num()] == 0) {
            q.emplace(str.append("R"), reg2num());
            visited[reg2num()] = 1;
        }

        num2reg(buf);
        str = cur.first;
        func_S();
        if(visited[reg2num()] == 0) {
            q.emplace(str.append("S"), reg2num());
            visited[reg2num()] = 1;
        }
    }
    return "";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int x1, x2;
    for(int i = 0; i < N; i++){
        cin >> x1 >> x2;
        num2reg(x1);
        cout << getResult(x2) << "\n";
    }
}