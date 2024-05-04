#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Vemaybay
{
private:
    string tenchuyen;
    string ngaybay;
    int giave;

public:
    Vemaybay(string ten, string ngay, int gia) : tenchuyen(ten), ngaybay(ngay), giave(gia) {}
    ~Vemaybay() {}

    void Nhap()
    {
        cout << "Nhap ten chuyen: ";
        cin >> tenchuyen;
        cout << "Nhap ngay bay: ";
        cin >> ngaybay;
        cout << "Nhap gia ve: ";
        cin >> giave;
    }

    void Xuat()
    {
        cout << "Ten chuyen: " << tenchuyen << endl;
        cout << "Ngay bay: " << ngaybay << endl;
        cout << "Gia ve: " << giave << endl;
    }

    int getgiave()
    {
        return giave;
    }
};

class Nguoi
{
protected:
    string hoten;
    string gioitinh;
    int tuoi;

public:
    Nguoi(string ten, string gt, int age) : hoten(ten), gioitinh(gt), tuoi(age) {}
    ~Nguoi() {}

    void Nhap()
    {
        cout << "Nhap ho ten: ";
        cin >> hoten;
        cout << "Nhap gioi tinh: ";
        cin >> gioitinh;
        cout << "Nhap tuoi: ";
        cin >> tuoi;
    }

    void Xuat()
    {
        cout << "Ho ten: " << hoten << endl;
        cout << "Gioi tinh: " << gioitinh << endl;
        cout << "Tuoi: " << tuoi << endl;
    }
};

class HanhKhach : public Nguoi
{
private:
    Vemaybay *ve;
    int soluong;

public:
    HanhKhach(string ten, string gt, int age, int sl) : Nguoi(ten, gt, age), soluong(sl)
    {
        ve = new Vemaybay[sl];
        for (int i = 0; i < sl; i++)
        {
            ve[i].Nhap();
        }
    }

    ~HanhKhach()
    {
        delete[] ve;
    }

    void Nhap()
    {
        Nguoi::Nhap();
        cout << "Nhap so luong ve: ";
        cin >> soluong;
        ve = new Vemaybay[soluong];
        for (int i = 0; i < soluong; i++)
        {
            ve[i].Nhap();
        }
    }

    void Xuat()
    {
        Nguoi::Xuat();
        for (int i = 0; i < soluong; i++)
        {
            cout << "Ve " << i + 1 << ":" << endl;
            ve[i].Xuat();
        }
        cout << "Tong tien phai tra: " << tongtien() << endl;
    }

    int tongtien()
    {
        int total = 0;
        for (int i = 0; i < soluong; i++)
        {
            total += ve[i].getgiave();
        }
        return total;
    }
};

bool compareHanhKhach(HanhKhach &a, HanhKhach &b)
{
    return a.tongtien() > b.tongt