#include <iostream>
#include <vector>
#include <algorithm>

bool binary_search(std::vector<std::string>& v, std::string& str, int first, int last) {
    int mid = (first + last) / 2;
    while(first <= last) {
        if (v[mid] == str)
            return true;
        else if (v[mid] > str) {
            last = mid - 1;
            mid = (first + last) / 2;
        } else {
            first = mid + 1;
            mid = (first + last) / 2;
        }
    }
    return false;
}

int main() {
    int N, M;
    std::cin >> N >> M;

    std::string str;
    std::vector<std::string> words;
    for(int i = 0; i < N; i++){
        std::cin >> str;
        words.push_back(str);
    }
    std::sort(words.begin(), words.end());

    int cnt = 0;
    for(int i = 0; i < M; i++){
        std::cin >> str;
        if(binary_search(words, str, 0, words.size()-1)) {
            cnt++;
        }
    }
    std::cout << cnt;
}