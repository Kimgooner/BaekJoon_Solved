#include <iostream>
#include <vector>

int cnt = 0;
int tmp[600000];
std::vector<int> res;

void merge(int arr[], int first, int mid, int last){
    int i = first;
    int j = mid+1;
    int t = 1;
    while(i <= mid && j <= last) {
        if (arr[i] <= arr[j]) {
            tmp[t] = arr[i++];
            res.push_back(tmp[t++]);
        }
        else {
            tmp[t] = arr[j++];
            res.push_back(tmp[t++]);
        }
        cnt++;
    }
    while(i <= mid) {
        tmp[t] = arr[i++];
        res.push_back(tmp[t++]);
        cnt++;
    }
    while (j <= last) {
        tmp[t] = arr[j++];
        res.push_back(tmp[t++]);
        cnt++;
    }
    i = first; t = 1;
    while (i <= last) {
        arr[i++] = tmp[t++];
    }
}

void merse_sort(int arr[], int first, int last){
    if(first < last){
        int mid = (first + last) / 2;
        merse_sort(arr, first, mid);
        merse_sort(arr, mid+1, last);
        merge(arr, first, mid, last);
    }
}

int main() {
    int N, M;
    std::cin >> N >> M;
    int size = N;

    int arr[N+10000];
    int idx = 0;
    int input;
    while(N--) {
        std::cin >> input;
        arr[idx++] = input;
    }
    merse_sort(arr, 0, size-1);

    if(cnt < M)
        std::cout << -1;
    else{
        std::cout << res[M-1];
    }
}