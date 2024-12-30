#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int stick[200001];
int cnt[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> stick[i];
    }

    int s = 0, e = 0;
    int result = 0;
    int unique_count = 0;

    while (e < N) {
        if (cnt[stick[e]] == 0) {
            unique_count++;
        }
        cnt[stick[e]]++;
        e++;

        while (unique_count > 2) {
            cnt[stick[s]]--;
            if (cnt[stick[s]] == 0) {
                unique_count--;
            }
            s++;
        }

        result = max(result, e - s);
    }

    cout << result;
}
