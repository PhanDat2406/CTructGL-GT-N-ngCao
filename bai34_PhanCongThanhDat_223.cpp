#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

struct NgaySinh{
    int ngay;
    int thang;
    int nam;
};

struct NhanVien{
    int maNV;
    string hoTen;
    NgaySinh ngaySinh;
    float luong;
};

void nhap(NhanVien nv[], int n){
    cout<<"Nhap thong tin "<<n<<" nhan vien:"<<endl;

    for(int i=0; i<n; i++){
        cout<<"Nhap ma nhan vien thu "<<i+1<<": ";
        cin>>nv[i].maNV;
        cin.ignore();

        cout<<"Nhap ho ten nhan vien thu "<<i+1<<": ";
        getline(cin,nv[i].hoTen);

        cout<<"Nhap ngay sinh nhan vien thu "<<i+1<<":"<<endl;
        cout<<"Ngay: ";
        cin>>nv[i].ngaySinh.ngay;

        cout<<"Thang: ";
        cin>>nv[i].ngaySinh.thang;

        cout<<"Nam: ";
        cin>>nv[i].ngaySinh.nam;

        cout<<"Nhap luong nhan vien thu "<<i+1<<" (trieu dong): ";
        cin>>nv[i].luong;
    }
}

void xuat(NhanVien nv[], int n){
    cout<<"Hien thi thong tin "<<n<<" nhan vien:"<<endl;

    cout<<"|----------|--------------------|--------------|----------|"<<endl;
    cout<<"|"<<left<<setw(10)<<"Ma NV"
        <<"|"<<setw(20)<<"Ho ten"
        <<"|"<<setw(14)<<"Ngay sinh"
        <<"|"<<setw(10)<<"Luong"
        <<"|"<<endl;
    cout<<"|----------|--------------------|--------------|----------|"<<endl;

    for(int i=0; i<n; i++){
        string ngaySinh = to_string(nv[i].ngaySinh.ngay) + "/" +
                          to_string(nv[i].ngaySinh.thang) + "/" +
                          to_string(nv[i].ngaySinh.nam);

        cout<<"|"<<left<<setw(10)<<nv[i].maNV
            <<"|"<<setw(20)<<nv[i].hoTen
            <<"|"<<setw(14)<<ngaySinh
            <<"|"<<setw(10)<<nv[i].luong
            <<"|"<<endl;

        cout<<"|----------|--------------------|--------------|----------|"<<endl;
    }
}

void bubbleSort(NhanVien nv[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=n-1; j>i; j--){
            if(nv[j].luong < nv[j-1].luong){
                NhanVien temp = nv[j];
                nv[j] = nv[j-1];
                nv[j-1] = temp;
            }
        }
    }
}

void timKiemNhiPhan(NhanVien nv[], int n, float X){
    int dau = 0;
    int cuoi = n - 1;
    int mid;
    int viTri = -1;

    while(dau <= cuoi){
        mid = (dau + cuoi) / 2;

        if(nv[mid].luong == X){
            viTri = mid;
            break;
        }
        else if(nv[mid].luong < X){
            dau = mid + 1;
        }
        else{
            cuoi = mid - 1;
        }
    }

    if(viTri == -1){
        cout<<"Khong tim thay nhan vien co luong bang "<<X<<" trieu dong."<<endl;
        return;
    }

    int dauX = viTri;
    int cuoiX = viTri;

    while(dauX > 0 && nv[dauX - 1].luong == X){
        dauX--;
    }

    while(cuoiX < n-1 && nv[cuoiX + 1].luong == X){
        cuoiX++;
    }

    cout<<"Cac nhan vien co luong bang "<<X<<" trieu dong:"<<endl;

    cout<<"|----------|--------------------|--------------|----------|"<<endl;
    cout<<"|"<<left<<setw(10)<<"Ma NV"
        <<"|"<<setw(20)<<"Ho ten"
        <<"|"<<setw(14)<<"Ngay sinh"
        <<"|"<<setw(10)<<"Luong"
        <<"|"<<endl;
    cout<<"|----------|--------------------|--------------|----------|"<<endl;

    for(int i=dauX; i<=cuoiX; i++){
        string ngaySinh = to_string(nv[i].ngaySinh.ngay) + "/" +
                          to_string(nv[i].ngaySinh.thang) + "/" +
                          to_string(nv[i].ngaySinh.nam);

        cout<<"|"<<left<<setw(10)<<nv[i].maNV
            <<"|"<<setw(20)<<nv[i].hoTen
            <<"|"<<setw(14)<<ngaySinh
            <<"|"<<setw(10)<<nv[i].luong
            <<"|"<<endl;

        cout<<"|----------|--------------------|--------------|----------|"<<endl;
    }
}

int main(){
    int n;

    do{
        cout<<"Nhap so luong nhan vien (>0): ";
        cin>>n;
    }while(n<=0);

    NhanVien *NV = new NhanVien[n];

    nhap(NV,n);

    cout<<endl;
    xuat(NV,n);

    bubbleSort(NV,n);

    cout<<endl;
    cout<<"Danh sach nhan vien sau khi sap xep tang dan theo luong:"<<endl;
    xuat(NV,n);

    float X;
    cout<<endl;
    cout<<"Nhap X: ";
    cin>>X;

    timKiemNhiPhan(NV,n,X);

    delete[] NV;

    return 0;
}
