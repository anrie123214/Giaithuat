#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct HangHoa {
    std::string maHang;
    std::string tenHang;
    int soLuong{};
};

int main() {
    std::ifstream file("hanghoa.txt");
    int n;
    if (!(file >> n)) return 1;

    std::vector<HangHoa> products(n);
    for (auto& product : products)
        file >> product.maHang >> product.tenHang >> product.soLuong;

    std::cout << "Danh sach san pham co so luong lon hon 5:\n";
    for (const auto& product : products)
        if (product.soLuong > 5)
            std::cout << '-' << product.maHang << ", " << product.tenHang
                      << ", " << product.soLuong << '\n';

    std::cout << "Nhap ma san pham can tim: ";
    std::string code;
    std::cin >> code;
    for (const auto& product : products) {
        if (product.maHang == code) {
            std::cout << "San pham da duoc tim thay.\n"
                      << "Thong tin san pham: " << product.maHang << ", "
                      << product.tenHang << ", " << product.soLuong << '\n';
            return 0;
        }
    }
    std::cout << "San pham khong duoc tim thay.\n";
}
