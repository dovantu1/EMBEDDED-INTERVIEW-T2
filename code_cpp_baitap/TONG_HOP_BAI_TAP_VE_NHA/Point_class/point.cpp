/*
*File: point.cpp
*author: Do Van Tu
*Date: 27/05/2023
*Description: chương trình tính khoảng cách giữa 2 điểm,
* tính diện tích của tam giác được tạo bởi 3 điểm
*/

#include <iostream>
#include <cmath>
/*
*class point
*input:x,y
*fuction:caculate_distance,caculate_area
*output:none
*/
class point {
private:
    double x;
    double y;

public:

/*
*constructor: point
*input:x,y
*output:none
*description: khởi tạo giá trị tọa độ x, y cho 1 điểm
*/
    point() 
    {
        std::cout<<"input x_val: ";
        std::cin>>x;
        
        std::cout<<"input y_val: ";
        std::cin>>y;
    }
    //~point();
/*
*fuction:caculate_distance
*input:point_deffer
*output:return caculate_distance
*description: trả về giá trị tính khoảng cách của điểm gốc và điểm input
*/
    double caculate_distance(const point& point_deffer) const {
        double dx = x - point_deffer.x;
        double dy = y - point_deffer.y;
        return std::sqrt(dx * dx + dy * dy);
    }
/*
*fuction:caculate_area
*input:point_one,point_two
*output:return caculate_area
*description: trả về giá trị tính diện tích của 3 canh AB,AC,BC 
*/
    double caculate_area(const point& point_one, const point& point_two) const {
        double a = caculate_distance(point_one);
        double b = caculate_distance(point_two);
        double c = point_one.caculate_distance(point_two);
        double p = (a + b + c) / 2; // Nửa chu vi tam giác
        return std::sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

int main() {
    // Tạo các điểm
    std::cout<<"initial point A"<<std::endl;
    point A;
    std::cout<<"initial point B"<<std::endl;
    point B;
    std::cout<<"initial point C"<<std::endl;
    point C;

    // Tính khoảng cách giữa hai điểm A và B
    double distance_AB = A.caculate_distance(B);
    std::cout << "distance between point A and poitn B: " << distance_AB << std::endl;

    // Tính diện tích tam giác ABC
    double area_ABC = A.caculate_area(B, C);
    std::cout << "area ABC: " << area_ABC << std::endl;
    return 0;
}