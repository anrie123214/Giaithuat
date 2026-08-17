#include <iostream>

struct PhanSo { long long tuSo, mauSo; };

PhanSo quyDong(PhanSo a, PhanSo b) { return {a.tuSo * b.mauSo, a.mauSo * b.mauSo}; }
PhanSo cong(PhanSo a, PhanSo b) { return {a.tuSo * b.mauSo + b.tuSo * a.mauSo, a.mauSo * b.mauSo}; }
PhanSo tru(PhanSo a, PhanSo b) { return {a.tuSo * b.mauSo - b.tuSo * a.mauSo, a.mauSo * b.mauSo}; }
PhanSo nhan(PhanSo a, PhanSo b) { return {a.tuSo * b.tuSo, a.mauSo * b.mauSo}; }
PhanSo chia(PhanSo a, PhanSo b) { return {a.tuSo * b.mauSo, a.mauSo * b.tuSo}; }
void print(const PhanSo& value) { std::cout << "tu so la " << value.tuSo << ", mau so la " << value.mauSo << '\n'; }

int main() {
    PhanSo a{}, b{};
    std::cout << "Nhap tu so thu nhat:\n"; std::cin >> a.tuSo;
    std::cout << "Nhap mau so thu nhat:\n"; std::cin >> a.mauSo;
    std::cout << "Nhap tu so thu hai:\n"; std::cin >> b.tuSo;
    std::cout << "Nhap mau so thu hai:\n"; std::cin >> b.mauSo;
    print(a); print(b);
    std::cout << "Phan so sau khi qui dong:\n"; print(quyDong(a, b));
    std::cout << "Phan so sau khi qui dong:\n"; print(quyDong(b, a));
    std::cout << "Phan so sau khi cong:\n"; print(cong(a, b));
    std::cout << "Phan so sau khi tru:\n"; print(tru(a, b));
    std::cout << "Phan so sau khi nhan:\n"; print(nhan(a, b));
    std::cout << "Phan so sau khi chia:\n"; print(chia(a, b));
}
