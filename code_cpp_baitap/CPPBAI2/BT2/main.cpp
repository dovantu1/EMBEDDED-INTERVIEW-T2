/*
*File: main.cpp
*Author: DoVanTu
*Date: 31/03/2027
*Description: Chương trình quả lý món ăn 
*/
#include <iostream>
#include <stdint.h>
#include <string>
#include <vector>
#define form(x) cout<<"----------------------------------------------------------------------------------\n";\
cout<<(x);
using namespace std;
const uint16_t keyerror = 20;
uint16_t keyin = keyerror;

class MonAn {
public:
    MonAn(int id, const string ten, double gia) : id(id), ten(ten), gia(gia) {}

    int getId() { return id; }
    const string getTen() { return ten; }
    double getGia() { return gia; }

    void setTen(string ten) { this->ten = ten; }
    void setGia(double gia) { this->gia = gia; }

private:
    int id;
    string ten;
    double gia;
};
typedef struct soMonAn {
    MonAn mon_an;
    uint8_t so_luong;
    soMonAn(MonAn monan, uint8_t soluong) :mon_an(monan), so_luong(soluong) {};
} soMonAn;
class Ban {
public:
    Ban(int soBan) : soBan(soBan), trangThai(false) {}

    int getSoBan() { return soBan; }
    bool getTrangThai() { return trangThai; }
    void setTrangThai(bool trangThai) { this->trangThai = trangThai; }
    void themMon(soMonAn soMonAn){danhSachSoLuongMonAn.push_back(soMonAn);}

    vector<soMonAn>& getDanhSachSoMonAn() { return danhSachSoLuongMonAn; }
private:
    vector<soMonAn> danhSachSoLuongMonAn;
    int soBan;
    bool trangThai;
};

class QuanLy {
public:
    QuanLy() : id(100) {}

    void setSoLuongBan(int n) {
        for (int i = 1; i <= n; i++) {
            danhSachBan.push_back(Ban(i));
        }
    }

    void themMonAn(string ten, double gia) {
        danhSachMonAn.push_back(MonAn(id++, ten, gia));
    }

    void xoaMonAn(int id) {
        for (size_t i = 0; i < danhSachMonAn.size(); i++) {
            if (danhSachMonAn[i].getId() == id) {
                danhSachMonAn.erase(danhSachMonAn.begin() + i);
                break;
            }
        }
    }

    void suaMonAn(int id, string tenMoi, double giaMoi) {
        for (MonAn& monAn : danhSachMonAn) {
            if (monAn.getId() == id) {
                monAn.setTen(tenMoi);
                monAn.setGia(giaMoi);
                break;
            }
        }
    }
    vector<Ban>& getDanhSachBan() { return danhSachBan; }
    vector<MonAn>& getDanhSachMonAn() { return danhSachMonAn; }
private:
    int id;
    vector<Ban> danhSachBan;
    vector<MonAn> danhSachMonAn;
};

class NhanVien {
public:
    NhanVien(QuanLy* quanLy) : quanLy(quanLy){}

    void hienThiDanhSachBan() {
        vector<Ban>& danhSachBan = quanLy->getDanhSachBan();
        if (danhSachBan.size()> 0)
        { 
            form("|NameTable|Status|\n");
        }
        for ( Ban& ban : danhSachBan) {
            // Thêm phần hiển thị ở đây
            cout<< "|\t";
            cout<<ban.getSoBan();
            cout<<"|";
            printf("\t%d|\n", ban.getTrangThai());
        }
        if (danhSachBan.size() > 0)
        {
            form("NameTable\t|Status\t|\n");
        }
    }

    void goiMon(int soBan, int idMonAn, int soLuong) {
        MonAn Mon_An(0, "none", 0);
        Ban& ban = quanLy->getDanhSachBan()[soBan - 1];
        ban.setTrangThai(true);
        for (MonAn & mon: quanLy->getDanhSachMonAn())
        {
            soMonAn so_MonAn(Mon_An, 0);
            if (mon.getId() == idMonAn)
            {
                so_MonAn.mon_an = mon;
                so_MonAn.so_luong = soLuong;
                ban.themMon(so_MonAn);
            }
        }
        // Them logic xu ly goi mon o day
    }

    void suaMon(int soBan, int idMonAnCu, int idMonAnMoi, int soLuong) {
        // Them logic xu ly sua mon o day
    }

    void themMon(int soBan, int idMonAn, int soLuong) {
        // Them logic xu ly them mon o day
    }

    void thanhToan(int soBan) {
        Ban& ban = quanLy->getDanhSachBan()[soBan - 1];
        ban.setTrangThai(false);
        for (soMonAn& soMonAn : quanLy->getDanhSachBan()[soBan - 1].getDanhSachSoMonAn())
        {
            cout << soMonAn.mon_an.getId() << soMonAn.mon_an.getTen().c_str() <<soMonAn.mon_an.getGia()<<soMonAn.so_luong<<endl;
        }
        // Them logic xu ly thanh toan o day
    }

private:
    QuanLy* quanLy;
};
QuanLy Manager_Program()
{
    QuanLy ql0;
    
    cout << "Manager_Program !\n";
    cout << "1: set number of table\n";
    cout << "2: add food base \n";
    cout << "3: del a food base\n";
    cout << "4: edit a food base\n";
    cout << "5: edit a food base\n";
    cout << "6: edit a food base\n";
    cout << "7: list foods base\n";
    cout << " 0: exit\n";
    switch (switch_on)
    {
    default:
        break;
    }
    ql0.setSoLuongBan();

}
int main(int argc, char const* argv[])
{
    enum keyIn { key0, key1, key2, key3, key4, key5,error_key};
    uint16_t key_in= error_key;
    QuanLy quanly0;
    quanly0.setSoLuongBan(10);
    int ID_food=0;
    int number_of_dishes=0;
    int number_table=0;
    string namefood = {"\n"};
    double pricefood=0.0;
    NhanVien nv1(&quanly0);
    while (1)
    {
        cout << "select otion\n";
        cout << "0: add food(databasefood)\n";
        cout << "1: show list food information\n";
        cout << "2: order food\n";
        cout << "keyin: ";
        cin>>key_in;
        switch (key_in)
        {
            case key0:
            cout << "input name food: ";
            cin >> namefood;
            cout << "input price food: ";
            cin >> pricefood;
            quanly0.themMonAn(namefood, pricefood);
            break;
            case key1:
                cout << "show list food information\n";
                form("|ID\t|Name Food|Price Food|\n");
                for (MonAn& mon : quanly0.getDanhSachMonAn())
                {
                    cout <<"|";
                    cout << mon.getId()<<"\t|";
                    cout << mon.getTen()<<"\t   |";
                    cout << mon.getGia()<< "\t\t|"<<endl;
                }
                break;
            case key2:
                nv1.hienThiDanhSachBan();
                cout << "number table: ";
                cin >> number_table;
                cout << "input ID: ";
                cin >> ID_food;
                //for()
                cout << "numbre of dishes: ";
                cin >> number_of_dishes;
                nv1.goiMon(number_table, ID_food, number_of_dishes);
                break;
            default:
                cout << "error key please again!";
                break;
        }
    }
    return 0;
}
