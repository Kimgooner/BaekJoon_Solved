#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> x;
    std::vector<int> y;

    int xi, yi;
    for(int i = 0; i < N; i++){
        std::cin >> xi >> yi;
        x.push_back(xi);
        y.push_back(yi);
    }
    std::sort(x.begin(),x.end());
    std::sort(y.begin(),y.end());

    int x_max = *x.begin();
    int x_min = *(x.end()-1);
    int y_max = *y.begin();
    int y_min = *(y.end()-1);

    int width = x_max - x_min;
    int height = y_max - y_min;

    std::cout << height * width;
}