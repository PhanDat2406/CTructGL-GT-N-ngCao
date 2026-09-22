#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct SinhVien
{
    int maSV;
    string tenSV;
    string lop;
    float tongKet;
    string hanhKiem;
};

struct Node
{
    SinhVien data;
    Node* left;
    Node* right;
};

typedef Node* NodePtr;

void init(NodePtr& T)
{
    T = NULL;
}

NodePtr createNode(SinhVien sv)
{
    NodePtr p = new Node;

    p->data = sv;
    p->left = NULL;
    p->right = NULL;

    return p;
}

void insert(NodePtr& T, SinhVien sv)
{
    if (T == NULL)
    {
        T = createNode(sv);
        return;
    }
    
    if (sv.maSV < T->data.maSV)
    {
        insert(T->left, sv);
    }

    else if (sv.maSV > T->data.maSV)
    {
        insert(T->right, sv);
    }

    else
    {
        cout << "Ma sinh vien " << sv.maSV << " da ton tai!\n";
    }
}

NodePtr search(int maSV, NodePtr T)
{

    if (T == NULL)
    {
        return NULL;
    }

    if (maSV == T->data.maSV)
    {
        return T;
    }

    if (maSV < T->data.maSV)
    {
        return search(maSV, T->left);
    }

    return search(maSV, T->right);
}

void inOrder(NodePtr T)
{
    if (T != NULL)
    {
        inOrder(T->left);

        cout << left
             << setw(10) << T->data.maSV
             << setw(25) << T->data.tenSV
             << setw(15) << T->data.lop
             << setw(12) << T->data.tongKet
             << setw(15) << T->data.hanhKiem
             << endl;
             
        inOrder(T->right);
    }
}

void printNode(NodePtr p)
{
    cout << "Ma sinh vien: " << p->data.maSV << endl;
    cout << "Ten sinh vien: " << p->data.tenSV << endl;
    cout << "Lop: " << p->data.lop << endl;
    cout << "Tong ket: " << p->data.tongKet << endl;
    cout << "Hanh kiem: " << p->data.hanhKiem << endl;
}


int main()
{
    NodePtr T;

    init(T);

    int n;

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        SinhVien sv;

        cout << "\n--- Nhap sinh vien thu " << i + 1 << " ---\n";

        cout << "Ma sinh vien: ";
        cin >> sv.maSV;

        cin.ignore();

        cout << "Ten sinh vien: ";
        getline(cin, sv.tenSV);

        cout << "Lop: ";
        getline(cin, sv.lop);

        cout << "Tong ket: ";
        cin >> sv.tongKet;

        cin.ignore();

        cout << "Hanh kiem (Tot/Kha/Trung binh/Yeu): ";
        getline(cin, sv.hanhKiem);

        insert(T, sv);
    }

    cout << "\n\n========== DANH SACH SINH VIEN ==========\n";

    cout << left
         << setw(10) << "Ma SV"
         << setw(25) << "Ten SV"
         << setw(15) << "Lop"
         << setw(12) << "Tong ket"
         << setw(15) << "Hanh kiem"
         << endl;

    cout << string(77, '-') << endl;

    inOrder(T);

    int maSV;

    cout << "\nNhap ma sinh vien can tim: ";
    cin >> maSV;

    NodePtr found = search(maSV, T);

    if (found == NULL)
    {
        cout << "-> Khong tim thay sinh vien co ma: "
             << maSV << endl;
    }
    else
    {
        cout << "\n-> Tim thay sinh vien co ma: "
             << maSV << endl;

        cout << "-----------------------------\n";

        printNode(found);
    }

    return 0;
}