#include <iostream>
#include <string>

using namespace std;

struct NhanVien {
    int ma;
    string ten;
    string ngaysinh;
    double luong;
};

void nhap1(NhanVien &nv) {
    cout << "  Nhap ma nhan vien: ";
    cin >> nv.ma;
    cin.ignore();

    cout << "  Nhap ho ten: ";
    getline(cin, nv.ten);

    cout << "  Nhap ngay sinh (dd/mm/yyyy): ";
    getline(cin, nv.ngaysinh);

    cout << "  Nhap luong (trieu dong): ";
    cin >> nv.luong;
}

void xuat1(NhanVien nv) {
    cout << "Ma NV: " << nv.ma 
         << " | Ten: " << nv.ten 
         << " | Ngay sinh: " << nv.ngaysinh 
         << " | Luong: " << nv.luong << " trieu" << endl;
}

void nhapDS(NhanVien a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap nhan vien thu " << i + 1 << " ---" << endl;
        nhap1(a[i]);
    }
}

void xuatDS(NhanVien a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". ";
        xuat1(a[i]);
    }
}

void sapXep(NhanVien a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j].luong > a[j + 1].luong) {
                NhanVien temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void timKiem(NhanVien a[], int n, double x) {
    int l = 0;
    int r = n - 1;
    int pos = -1;

    while (l <= r) {
        int m = (l + r) / 2;

        if (a[m].luong == x) {
            pos = m;
            break;
        }
        if (a[m].luong < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    if (pos == -1) {
        cout << "\nKhong co nhan vien nao co luong bang " << x << " trieu" << endl;
        return;
    }

    cout << "\n=== DANH SACH NHAN VIEN CO LUONG = " << x << " TRIEU ===" << endl;

    int dau = pos;
    while (dau - 1 >= 0 && a[dau - 1].luong == x) {
        dau--;
    }

    int cuoi = pos;
    while (cuoi + 1 < n && a[cuoi + 1].luong == x) {
        cuoi++;
    }

    for (int i = dau; i <= cuoi; i++) {
        xuat1(a[i]);
    }
}

int main() {
    int n;
    cout << "Nhap so luong nhan vien n: ";
    cin >> n;

    if (n <= 0) {
        cout << "So luong nhan vien phai lon hon 0!" << endl;
        return 0;
    }

    NhanVien a[100];

    nhapDS(a, n);
    cout << "\nDANH SACH NHAN VIEN VUA NHAP" << endl;
    xuatDS(a, n);

    sapXep(a, n);
    cout << "\nDANH SACH SAU KHI SAP XEP TANG DAN THEO LUONG" << endl;
    xuatDS(a, n);

    double x;
    cout << "\nNhap luong X can tim: ";
    cin >> x;
    timKiem(a, n, x);

    return 0;
}
