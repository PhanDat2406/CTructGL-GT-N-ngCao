#include <iostream>
#include <cstdio>

using namespace std;

#define VOCUNG 1000000000

// Cấu trúc đồ thị
struct Graph {
    int N;
    int **A;
};

// Cấu trúc bài toán Dijkstra
struct Dijkstra {
    Graph graph;
    int start;
    int end;
};

void Nhap(Dijkstra &d)
{
    // Mở file Grap.txt để chuyển hướng luồng nhập stdin
    FILE* f = freopen("Grap.txt", "r", stdin);
    if (f == NULL) {
        cout << "Khong the mo file Grap.txt!" << endl;
        return;
    }

    // Nhập số đỉnh của đồ thị
    cin >> d.graph.N;

    // Cấp phát bộ nhớ cho ma trận kề/trọng số A
    d.graph.A = new int*[d.graph.N];
    for (int i = 0; i < d.graph.N; i++)
    {
        d.graph.A[i] = new int[d.graph.N];
        for (int j = 0; j < d.graph.N; j++)
        {
            cin >> d.graph.A[i][j];
            // Nếu không có đường đi (bằng 0 và i != j), gán bằng VOCUNG
            if (d.graph.A[i][j] == 0 && i != j) {
                d.graph.A[i][j] = VOCUNG;
            }
        }
    }

    fclose(f);
}


// CÂU 3: Cài đặt hàm HienThi để xuất ma trận ra màn hình
void HienThi(Dijkstra d)
{
    cout << "Do thi vua nhap la:" << endl;
    cout << "- So dinh cua do thi: " << d.graph.N << endl;
    cout << "- Ma tran trong so cua do thi:" << endl;
    for (int i = 0; i < d.graph.N; i++)
    {
        for (int j = 0; j < d.graph.N; j++)
        {
            if (d.graph.A[i][j] == VOCUNG)
                cout << 0 << "\t";
            else 
                cout << d.graph.A[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    Dijkstra d;
    
    // Câu 2: Gọi hàm Nhap
    Nhap(d);
    
    // Câu 3: Gọi hàm HienThi
    HienThi(d);

    return 0;
}