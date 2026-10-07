#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

struct KhachHang{
    int maKH;
    string tenKH, SDT;
    float tongTienThanhToan;
};

void nhap(KhachHang kh[], int n){
    cout<<"Nhap thong tin "<<n<<" khach hang: "<<endl;
    for(int i=0; i<n; i++){
        cout<<"Nhap ma khach hang thu "<<i+1<<": ";
        cin>>kh[i].maKH;
        cin.ignore();

        cout<<"Nhap ten khach hang thu "<<i+1<<": ";
        getline(cin, kh[i].tenKH);

        cout<<"Nhap so dien thoai khach hang thu "<<i+1<<": ";
        getline(cin, kh[i].SDT);

        cout<<"Nhap tong tien thanh toan cua khach hang thu "<<i+1<<": ";
        cin>>kh[i].tongTienThanhToan;
    }
}

void xuat(KhachHang *kh, int n){
    cout<<"Hien thi thong tin "<<n<<" khach hang:"<<endl;

    cout<<"|----------|--------------------|--------------------|----------|"<<endl;
    cout<<"|"<<left<<setw(10)<<"Ma KH"
        <<"|"<<setw(20)<<"Ten KH"
        <<"|"<<setw(20)<<"SDT"
        <<"|"<<setw(10)<<"tongTTT"
        <<"|"<<endl;
    cout<<"|----------|--------------------|--------------------|----------|"<<endl;

    for(int i=0; i<n; i++){
        cout<<"|"<<left<<setw(10)<<kh[i].maKH
            <<"|"<<setw(20)<<kh[i].tenKH
            <<"|"<<setw(20)<<kh[i].SDT
            <<"|"<<setw(10)<<kh[i].tongTienThanhToan
            <<"|"<<endl;

        cout<<"|----------|--------------------|--------------------|----------|"<<endl;
    }
}
void insertionSort(KhachHang kh[], int n){
    for(int i=1; i<n; i++){
        KhachHang x = kh[i];
        int pos = i - 1;

        while(pos >= 0 && kh[pos].tongTienThanhToan > x.tongTienThanhToan){
            kh[pos + 1] = kh[pos];
            pos--;
        }

        kh[pos + 1] = x;
    }
}




void timKiemNhiPhan(KhachHang kh[], int n, float X){
    int left = 0;
    int right = n - 1;
    int mid;
    int viTri = -1;

    while(left <= right){
        mid = (left + right) / 2;

        if(kh[mid].tongTienThanhToan == X){
            viTri = mid;
            break;
        }
        else if(kh[mid].tongTienThanhToan < X){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    if(viTri == -1){
        cout<<"Khong tim thay khach hang co tong tien thanh toan bang "<<X<<endl;
        return;
    }

    int dau = viTri;
    int cuoi = viTri;

    while(dau > 0 && kh[dau - 1].tongTienThanhToan == X){
        dau--;
    }

    while(cuoi < n - 1 && kh[cuoi + 1].tongTienThanhToan == X){
        cuoi++;
    }

    cout<<"Cac khach hang co tong tien thanh toan bang "<<X<<":"<<endl;

    cout<<"|----------|--------------------|--------------------|----------|"<<endl;
    cout<<"|"<<left<<setw(10)<<"Ma KH"
        <<"|"<<setw(20)<<"Ten KH"
        <<"|"<<setw(20)<<"SDT"
        <<"|"<<setw(10)<<"tongTTT"
        <<"|"<<endl;
    cout<<"|----------|--------------------|--------------------|----------|"<<endl;

    for(int i=dau; i<=cuoi; i++){
        cout<<"|"<<left<<setw(10)<<kh[i].maKH
            <<"|"<<setw(20)<<kh[i].tenKH
            <<"|"<<setw(20)<<kh[i].SDT
            <<"|"<<setw(10)<<kh[i].tongTienThanhToan
            <<"|"<<endl;

        cout<<"|----------|--------------------|--------------------|----------|"<<endl;
    }
}

int main(){
    int n;

    do{
        cout<<"Nhap so luong khach hang(>0): ";
        cin>>n;
    }while(n<=0);

    KhachHang *KH = new KhachHang[n];

    nhap(KH,n);

    cout<<endl;
    xuat(KH,n);

    insertionSort(KH,n);

    cout<<endl;
    cout<<"Danh sach khach hang sau khi sap xep tang dan theo tong tien thanh toan:"<<endl;
    xuat(KH,n);

    float X;
    cout<<endl;
    cout<<"Nhap X: ";
    cin>>X;

    timKiemNhiPhan(KH,n,X);

    delete[] KH;

    return 0;
}
