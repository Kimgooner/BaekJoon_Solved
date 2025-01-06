#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int tree[30][2];

void visit(int n){
    char output = n - 1 + 'A';
    cout << output;
}

void preorder(int n){
    visit(n);
    if(tree[n][0] != 0) preorder(tree[n][0]);
    if(tree[n][1] != 0) preorder(tree[n][1]);
}

void inorder(int n){
    if(tree[n][0] != 0) inorder(tree[n][0]);
    visit(n);
    if(tree[n][1] != 0) inorder(tree[n][1]);
}

void postorder(int n){
    if(tree[n][0] != 0) postorder(tree[n][0]);
    if(tree[n][1] != 0) postorder(tree[n][1]);
    visit(n);
}

int main(){
    cin >> N;

    char i1, i2, i3;
    for(int i = 0; i < N; i++){
        cin >> i1 >> i2 >> i3;

        int root = (i1 - 'A') + 1;

        int left, right;
        if(i2 == '.') left = 0;
        else left = (i2 - 'A') + 1;

        if(i3 == '.') right = 0;
        else right = (i3 - 'A') + 1;

        tree[root][0] = left;
        tree[root][1] = right;
    }
    preorder(1);
    cout << "\n";

    inorder(1);
    cout << "\n";

    postorder(1);
    cout << "\n";
}