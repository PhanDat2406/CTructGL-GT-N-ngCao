#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct NgayThang {
    int ngay;
    int thang;
    int nam;
};

struct HangHoa {
    string maHH;
    string tenHH;
    NgayThang ngayXuat;
    double giaXuat;
};

void nhapMotHangHoa(HangHoa &hh) {
    char slash;
    cout << "  - Nhap ma hang hoa: ";
    getline(cin, hh.maHH);
    cout << "  - Nhap ten hang hoa: ";
    getline(cin, hh.tenHH);
    cout << "  - Nhap ngay xuat (dd/mm/yyyy): ";
    cin >> hh.ngayXuat.ngay >> slash >> hh.ngayXuat.thang >> slash >> hh.ngayXuat.nam;
    cout << "  - Nhap gia xuat (trieu dong): ";
    cin >> hh.giaXuat;
    cin.ignore();
}

void nhapDanhSach(HangHoa a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin hang hoa thu " << i + 1 << " ---" << endl;
        nhapMotHangHoa(a[i]);
    }
}

void inTieuDe() {
    cout << left << setw(12) << "Ma HH"
         << setw(25) << "Ten hang hoa"
         << setw(16) << "Ngay xuat"
         << right << setw(18) << "Gia xuat (trieu)" << endl;
    cout << string(71, '-') << endl;
}

void inMotHangHoa(const HangHoa &hh) {
    string strNgay = (hh.ngayXuat.ngay < 10 ? "0" : "") + to_string(hh.ngayXuat.ngay) + "/" +
                     (hh.ngayXuat.thang < 10 ? "0" : "") + to_string(hh.ngayXuat.thang) + "/" +
                     to_string(hh.ngayXuat.nam);

    cout << left << setw(12) << hh.maHH
         << setw(25) << hh.tenHH
         << setw(16) << strNgay
         << right << setw(18) << fixed << setprecision(2) << hh.giaXuat << endl;
}

void xuatDanhSach(HangHoa a[], int n) {
    inTieuDe();
    for (int i = 0; i < n; i++) {
        inMotHangHoa(a[i]);
    }
}

void QuickSort(HangHoa a[], int left, int right) {
    double pivot = a[(left + right) / 2].giaXuat;
    int i = left, j = right;

    while (i <= j) {
        while (a[i].giaXuat < pivot) i++;
        while (a[j].giaXuat > pivot) j--;

        if (i <= j) {
            HangHoa tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j) QuickSort(a, left, j);
    if (i < right) QuickSort(a, i, right);
}

void timKiemTheoGia(HangHoa a[], int n, double x) {
    int left = 0, right = n - 1;
    int viTri = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid].giaXuat == x) {
            viTri = mid;
            break;
        } else if (a[mid].giaXuat < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (viTri == -1) {
        cout << "=> Khong tim thay hang hoa nao co gia bang " << fixed << setprecision(2) << x << " trieu dong." << endl;
        return;
    }

    int start = viTri;
    while (start > 0 && a[start - 1].giaXuat == x) {
        start--;
    }

    int end = viTri;
    while (end < n - 1 && a[end + 1].giaXuat == x) {
        end++;
    }

    cout << "\n=> Tim thay " << (end - start + 1) << " hang hoa co gia " << fixed << setprecision(2) << x << " trieu dong:\n";
    inTieuDe();
    for (int i = start; i <= end; i++) {
        inMotHangHoa(a[i]);
    }
}

int main() {
    int n;
    cout << "Nhap so luong hang hoa: ";
    cin >> n;
    while (n <= 0) {
        cout << "So luong phai lon hon 0. Nhap lai: ";
        cin >> n;
    }
    cin.ignore();

    HangHoa *a = new HangHoa[n];

    cout << "\n=== NHAP DANH SACH HANG HOA ===" << endl;
    nhapDanhSach(a, n);

    cout << "\n=== DANH SACH HANG HOA VUA NHAP ===" << endl;
    xuatDanhSach(a, n);

    QuickSort(a, 0, n - 1);
    cout << "\n=== DANH SACH HANG HOA SAU KHI SAP XEP TANG DAN THEO GIA ===" << endl;
    xuatDanhSach(a, n);

    double x;
    cout << "\nNhap gia xuat X can tim kiem (trieu dong): ";
    cin >> x;
    timKiemTheoGia(a, n, x);

    delete[] a;
    return 0;
}