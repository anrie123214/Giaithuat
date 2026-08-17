#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct SinhVien {
    std::string hoTen, ngaySinh;
    float diemToan{}, diemLy{}, diemHoa{};
    float diemTrungBinh() const { return (diemToan + diemLy + diemHoa) / 3.0f; }
};

void print(const SinhVien& student) {
    std::cout << "Ho ten: " << student.hoTen << "\nNgay sinh: " << student.ngaySinh
              << "\nDiem toan: " << student.diemToan << "\nDiem ly: " << student.diemLy
              << "\nDiem hoa: " << student.diemHoa
              << "\nDiem trung binh: " << student.diemTrungBinh() << "\n";
}

int main() {
    int n;
    std::cout << "Nhap so luong sinh vien: "; std::cin >> n;
    std::cin.ignore(10000, '\n');
    std::vector<SinhVien> students(n);
    for (auto& student : students) {
        std::cout << "Nhap ho ten sinh vien:\n"; std::getline(std::cin, student.hoTen);
        std::cout << "Nhap ngay sinh:\n"; std::getline(std::cin, student.ngaySinh);
        std::cout << "Nhap diem toan:\n"; std::cin >> student.diemToan;
        std::cout << "Nhap diem ly:\n"; std::cin >> student.diemLy;
        std::cout << "Nhap diem hoa:\n"; std::cin >> student.diemHoa;
        std::cin.ignore(10000, '\n');
    }

    std::cout << "Danh sach sinh vien co diem trung binh tren 5:\n";
    for (const auto& student : students)
        if (student.diemTrungBinh() > 5) print(student);

    std::sort(students.begin(), students.end(), [](const auto& a, const auto& b) {
        return a.diemTrungBinh() < b.diemTrungBinh();
    });
    std::cout << "Danh sach sinh vien sap xep tang dan theo diem trung binh:\n";
    for (const auto& student : students) print(student);
}
