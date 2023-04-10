/*
*File: main.cpp
*author: Do Van Tu
*Date: 01/04/2023
*Description: chương trình tính khoảng cách giữa 2 điểm,
* tính diện tích của tam giác được tạo bởi 3 điểm
*/
#include<math.h>
#include<iostream>
#include<math.h>
/*
*Fuction: macro PP(x)
*Description: yêu cầu nhập vào tọa độ của point 
* Input : số thứ tự point cần nhập
*/
#define PP(x) cout<<"please enter coordinate p"<<x<<"\n";
using namespace std;
/*
*Fuction: class point
*Description: chứa thuộc tính và phương thức của class point
*/
class point
{
private:
    /* data */
    float x_point;
    float y_point;
public:
    point(float point_x,float point_y);
    // ~point();
    void setPoint();
    float getX();
    float getY();
};
/*
*Fuction: Constructer point 
*Description: khởi tạo giá trị cho tọa độ 1 điểm trong không gian;
*Input: y:tung độ
*       x:hoành độ
*/
point::point(float point_x,float point_y)
{
    this->x_point=point_x;
    this->y_point=point_y;
}

void point::setPoint()
{
    cin>>this->x_point;
    cin>>this->y_point;
    cout<<"point("<<x_point<<","<<y_point<<")"<<endl;
}

float point::getX()
{
    return this->x_point;
}

float point::getY()
{
    return this->y_point;
}

/*
*Fuction: class space_math 
*Description: thuộc tính và phương thức sử dụng cho class space_math;
*/
class spaceMath
{
private:
    /* data */
    enum select_math{dis_two_point,area_tritangle,error_math}select_math;
    point p1=point(0,0);
    point p2=point(0,0);
    point p3=point(0,0);
    float mathCaculater(point p1,point p2);
public:
    spaceMath(/* args */);
    // ~space_math();
    void math(point p1,point p2,point p3);
    void math(point p1,point p2);
    float selectMath();
    void ProgramTwoPointDistanceAndAreaTriangle();
};
spaceMath::spaceMath(/* args */)
{

}

// space_math::~space_math()
// {
//     ;
// }

/*
*Fuction: math
*Description: nhập vào thông số của 2 point cần cho tính toán
*Input: p1: vị trí của điểm 1
*          p2: vị trí điểm 2
*/
void spaceMath::math(point p1,point p2)
{
    this->p1=p1;
    this->p2=p2;

}
/*
*Fuction: mathCaculater
*Description: công thức tính toán khoảng cách của 2 điểm
*Input: p1:vị trí của điểm 1
*          p2:vị trí điểm 2
*/
float spaceMath::mathCaculater(point p1,point p2)
{
    return(sqrt(pow((p1.getX()-p2.getX()),2)+pow((p1.getY()-p2.getY()),2)));
}

/*
*Fuction: math
*Description: nhập vào thông số của 3 point cần cho tính toán
*Input: p1:vị trí của điểm 1
*          p2:vị trí điểm 2
*          p3:vị trí điểm 3
*/
void spaceMath::math(point p1,point p2,point p3)
{
    this->p1=p1;
    this->p2=p2;
    this->p3=p3;
}

/*
*Fuction: selectMath
*Description: chọn phép toán cần tính
*/
float spaceMath::selectMath()
{
    uint16_t select_math=error_math;
    point p1(0,0),p2(0,0),p3(0,0);
    float halfPerimeter=0;
    cout<<"please select math: ";
    cin>>select_math;
    switch ((uint16_t) select_math)
    {
        case dis_two_point:
        { /* code */
            PP(1);
            p1.setPoint();
            PP(2);
            p2.setPoint();
            math(p1,p2);
            return mathCaculater(p1,p2);
            break;
        }
        case area_tritangle:
        {
            PP(1);
            p1.setPoint();
            PP(2);
            p2.setPoint();
            PP(3);
            p3.setPoint();
            math(p1,p2,p3);
            // công thức tính nửa chu vi
            halfPerimeter=(mathCaculater(this->p1,this->p2)+mathCaculater(this->p1,this->p3)+mathCaculater(this->p2,this->p3))/2;
            //công thức tính diện tích hình tam giác khi biết độ dài 3 cạnh;
            return(sqrt( halfPerimeter*( halfPerimeter-mathCaculater(this->p1,this->p2))*( halfPerimeter-mathCaculater(this->p1,this->p3))*( halfPerimeter-mathCaculater(this->p2,this->p3))));
            break;
        }
        default:
        {
            cout<<"error math"<<endl;
            return 0;
            break;
        }
    }
}

/*
*Fuction: ProgramTwoPointDistanceAndAreaTriangle
*Description: in ra màn hình kết quả của phép toán đã chọn
*/
void spaceMath::ProgramTwoPointDistanceAndAreaTriangle()
{
    float resultTheMath=0;
    resultTheMath=selectMath();
   cout<<"result the math: "<<resultTheMath<<endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    spaceMath spm0;
    cout<<"goooooooooooo\n";
    spm0.ProgramTwoPointDistanceAndAreaTriangle();
    return 0;
}

