#include <iostream>
#include <string>

struct SinhVien {
    std::string hoTen;
    std::string ngaySinh;
    float diemToan{}, diemLy{}, diemHoa{};
};

int main() {
    SinhVien student;
    std::cout << "Nhap ho ten sinh vien: ";
    std::getline(std::cin, student.hoTen);
    std::cout << "Nhap ngay sinh: ";
    std::getline(std::cin, student.ngaySinh);
    std::cout << "Nhap diem toan: "; std::cin >> student.diemToan;
    std::cout << "Nhap diem ly: "; std::cin >> student.diemLy;
    std::cout << "Nhap diem hoa: "; std::cin >> student.diemHoa;
    std::cin.ignore(10000, '\n');

    std::string canTim;
    std::cout << "Ho ten sv can tim\n";
    std::getline(std::cin, canTim);
    if (student.hoTen == canTim) {
        std::cout << "Thong tin sinh vien:\nHo ten: " << student.hoTen
                  << "\nNgay sinh: " << student.ngaySinh
                  << "\nDiem toan: " << student.diemToan
                  << "\nDiem ly: " << student.diemLy
                  << "\nDiem hoa: " << student.diemHoa << '\n';
    } else {
        std::cout << "Khong tim thay sinh vien co ho ten: " << canTim << '\n';
    }
}
