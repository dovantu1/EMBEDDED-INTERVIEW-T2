/*
*File: circle.cpp
*Author: Do Van Tu
*Date: 27/05/2023
*Description: chương trình tính chu vi và diện tích của một hình tròn với bán kính cho trước
*/

#include <iostream>
#include <cmath>

/*
*class circle
*input:radius
*fuction:calculate_circumference,caculate_area
*output:none
*/

class circle {
private:
    float radius;

public:

/*
*constructor: circle
*input:radius
*output:none
*description: khởi tạo giá trị bán kính cho một hình tròn
*/

    circle() {
        std::cout<<"input r: ";
        std::cin>>radius;
    }

/*
*fuction:calculate_circumference
*input:none
*output:return calculate_circumference
*description: trả về giá trị tính chu vi của một hình tròn
*/

    float calculate_circumference() {
        return 2 * M_PI * radius;
    }

/*
*fuction:calculate_area
*input:none
*output:return calculate_area
*description: trả về giá trị tính diện tích của một hình tròn
*/

    float calculate_area() {
        return M_PI * radius * radius;
    }
};

int main() {
    // khởi tạo giá trị bán kính cho hình tròn
    
    std::cout<<"initial radius circle"<<std::endl;
    circle circle;

    // tính chu vi của một hình tròn

    float circumference = circle.calculate_circumference();
    std::cout << "circumference of the circle: " << circumference << std::endl;

    // tính diện tích của một hình tròn

    float area = circle.calculate_area();
    std::cout << "area of the circle: " << area << std::endl;

    return 0;
}