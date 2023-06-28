#include <iostream>
#include <vector>
using namespace std;
class phepToan
{
private:
    int x,y;
    int phepNhan()
    {
        return x*y;
    }
    void datGiaTri(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
public:

    phepToan(int x=0,int y=0)
    {
        this->x=x;
        this->y=y;
    }
    void kiemTraKetQua(int x,int y)
    {
        datGiaTri(x,y);
        if(phepNhan()>0)
        {
            cout<<"ket qua duong";
        }
        else
        {
            cout<<"ket qua am";
        }
    }
};
int main(int argc, const char** argv) {
    return 0;
}



