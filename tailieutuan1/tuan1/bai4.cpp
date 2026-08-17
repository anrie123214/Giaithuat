#include <iostream>
#include <string>
#include <vector>

struct SinhVien {
    std::string hoTen, ngaySinh;
    float diemToan{}, diemLy{}, diemHoa{};
};

int main() {
    int n;
    std::cout << "Nhap so luong sinh vien: ";
    std::cin >> n;
    std::cin.ignore(10000, '\n');
    std::vector<SinhVien> students(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Nhap ho ten sinh vien thu " << i + 1 << ":\n";
        std::getline(std::cin, students[i].hoTen);
        std::cout << "Nhap ngay sinh:\n"; std::getline(std::cin, students[i].ngaySinh);
        std::cout << "Nhap diem toan:\n"; std::cin >> students[i].diemToan;
        std::cout << "Nhap diem ly:\n"; std::cin >> students[i].diemLy;
        std::cout << "Nhap diem hoa:\n"; std::cin >> students[i].diemHoa;
        std::cin.ignore(10000, '\n');
    }

    std::string code;
    std::cout << "Nhap ho ten sinh vien can tim\n";
    std::getline(std::cin, code);
    for (const auto& student : students) {
        if (student.hoTen == code) {
            std::cout << "Thong tin sinh vien can tim la\nHo ten: " << student.hoTen
                      << "\nNgay sinh: " << student.ngaySinh
                      << "\nDiem toan: " << student.diemToan
                      << "\nDiem ly: " << student.diemLy
                      << "\nDiem hoa: " << student.diemHoa << '\n';
            return 0;
        }
    }
    std::cout << "Khong tim thay sinh vien co ho ten: " << code << '\n';
}
