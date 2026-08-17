#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::ifstream file("input1.txt");
    int n;
    if (!(file >> n)) return 1;

    std::vector<int> values(n);
    for (int& value : values) file >> value;

    std::cout << "cac phan tu trong mang la:" << n << '\n';
    std::cout << "tong cac phan tu trong mang la "
              << std::accumulate(values.begin(), values.end(), 0) << '\n';

    std::cout << "so le trong mang la ";
    for (int value : values)
        if (value % 2 != 0) std::cout << value << ' ';
    std::cout << '\n';

    if (!values.empty()) {
        std::cout << "so nho nhat trong mang la "
                  << *std::min_element(values.begin(), values.end()) << '\n';
        std::cout << "so lon nhat trong mang la "
                  << *std::max_element(values.begin(), values.end()) << '\n';
    }

    std::cout << "so luong so le trong mang la "
              << std::count_if(values.begin(), values.end(),
                               [](int value) { return value % 2 != 0; }) << '\n';
}
