#include <iostream>
#include <vector>
#include <queue>

#define mod 1000;
using namespace std;

int N;
long long B;

typedef vector<vector<long long>> matrix;
matrix operator * (const matrix& a, const matrix& b){
    int size = a.size();
    matrix result(size, vector<long long>(size));

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
                result[i][j] += a[i][k] * b[k][j];
            }
            result[i][j] %= mod;
        }
    }
    return result;
}

matrix pow(matrix a, long long exp){
    int size = a.size();
    matrix result(size, vector<long long>(size));
    for(int i = 0; i < size; i++){
        result[i][i] = 1;
    }
    while (exp > 0){
        if(exp % 2 == 1) {result = (result * a); exp--;}
        else {a = a * a; exp/=2;}
    }
    return result;
}

void printMatrix(matrix& a){
    int size = a.size();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> B;
    matrix mat(N, vector<long long>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> mat[i][j];
        }
    }
    mat = pow(mat, B);
    printMatrix(mat);
}