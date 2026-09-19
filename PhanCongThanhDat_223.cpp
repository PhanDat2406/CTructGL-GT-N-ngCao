#include <iostream>
#include <string>
using namespace std;

// Cau 1: Dinh nghia cau truc HangHoa
struct HangHoa
{
    string maHang;
    string tenHang;
    int ngay;
    int thang;
    int nam;
    double giaXuat;
};

// Cau 2: Ham nhap mang n hang hoa
void nhapMang(HangHoa a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap hang hoa thu " << i + 1 << ":\n";

        cout << "Ma hang: ";
        cin >> a[i].maHang;

        cin.ignore();
        cout << "Ten hang: ";
        getline(cin, a[i].tenHang);

        cout << "Ngay xuat hang: ";
        cin >> a[i].ngay;

        cout << "Thang xuat hang: ";
        cin >> a[i].thang;

        cout << "Nam xuat hang: ";
        cin >> a[i].nam;

        cout << "Gia xuat hang (trieu dong): ";
        cin >> a[i].giaXuat;
    }
}

// Cau 3: Ham xuat mang n hang hoa
void xuatMang(HangHoa a[], int n)
{
    cout << "\n===== DANH SACH HANG HOA =====\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nHang hoa thu " << i + 1 << ":\n";
        cout << "Ma hang: " << a[i].maHang << endl;
        cout << "Ten hang: " << a[i].tenHang << endl;

        cout << "Ngay xuat: "
             << a[i].ngay << "/"
             << a[i].thang << "/"
             << a[i].nam << endl;

        cout << "Gia xuat: " << a[i].giaXuat
             << " trieu dong" << endl;
    }
}

// Cau 4: Selection Sort tang dan theo gia xuat hang
void selectionSort(HangHoa a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j].giaXuat < a[min].giaXuat)
            {
                min = j;
            }
        }

        // Hoan doi
        if (min != i)
        {
            HangHoa temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

// Cau 5: Tim kiem nhi phan hang hoa co gia = X
void binarySearch(HangHoa a[], int n, double X)
{
    int left = 0;
    int right = n - 1;
    int pos = -1;

    // Tim mot vi tri co gia = X
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (a[mid].giaXuat == X)
        {
            pos = mid;
            break;
        }
        else if (a[mid].giaXuat < X)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    // Khong tim thay
    if (pos == -1)
    {
        cout << "\nKhong co hang hoa nao co gia xuat = "
             << X << " trieu dong.\n";
        return;
    }

    cout << "\n===== CAC HANG HOA CO GIA = " << X << " =====\n";

    // Tim ve ben trai
    int i = pos;
    while (i >= 0 && a[i].giaXuat == X)
    {
        i--;
    }

    // i dang o vi tri truoc phan tu dau tien co gia X
    i++;

    // In cac phan tu co gia X
    while (i < n && a[i].giaXuat == X)
    {
        cout << "\nMa hang: " << a[i].maHang << endl;
        cout << "Ten hang: " << a[i].tenHang << endl;

        cout << "Ngay xuat: "
             << a[i].ngay << "/"
             << a[i].thang << "/"
             << a[i].nam << endl;

        cout << "Gia xuat: " << a[i].giaXuat
             << " trieu dong" << endl;

        i++;
    }
}

// Cau 6: Ham main
int main()
{
    int n;

    cout << "Nhap so luong hang hoa: ";
    cin >> n;

    HangHoa a[100];

    // Nhap hang hoa
    nhapMang(a, n);

    // Xuat danh sach ban dau
    cout << "\n\nDANH SACH BAN DAU:";
    xuatMang(a, n);

    // Sap xep tang dan theo gia
    selectionSort(a, n);

    // Xuat danh sach sau khi sap xep
    cout << "\n\nDANH SACH SAU KHI SAP XEP TANG DAN THEO GIA:";
    xuatMang(a, n);

    // Tim kiem
    double X;

    cout << "\n\nNhap gia X can tim: ";
    cin >> X;

    binarySearch(a, n, X);

    return 0;
}