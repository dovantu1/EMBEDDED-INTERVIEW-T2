/*
*File: point.cpp
*author: Do Van Tu
*Date: 27/05/2023
*Description: chương trình tính chu vi, diện tích, đường chéo của một hình chữ nhật
* và kiểm tra xem có phải hình vuông hay không
*/
#include <iostream>
#include <cmath>

/*
*class rectangle
*input:length, width
*fuction:caculate_primeter,caculate_area,caculate_diagonal_line
*output:none
*/

class rectangle {
private:
    float length;
    float width;

public:

/*
*constructor: rectangle
*input:length,width
*output:none
*description: khởi tạo giá trị độ dài, độ rộng của hình chữ nhật
*/
    rectangle() {
    std::cout<<"input length: ";
    std::cin>>length;
    std::cout<<"input width: ";
    std::cin>>width;
    }

/*
*fuction: caculate_primeter
*input:none
*output:return caculate_primeter
*description: tính toán chu vi của một hình chữ nhật
*/

    float caculate_primeter() {
        return 2 * (length + width);
    }

/*
*fuction: caculate_area
*input:none
*output:return caculate_area
*description: tính toán diện tích của một hình chữ nhật
*/

    float caculate_area() {
        return length * width;
    }

/*
*fuction: caculate_diagonal_line
*input:none
*output:return caculate_diagonal_line
*description: tính toán độ dài đường chéo của một hình chữ nhật
*/

    float caculate_diagonal_line() {
        return std::sqrt(length * length + width * width);
    }

/*
*fuction: check_square
*input:none
*output:return check_square
*description: kiểm tra hình chữ nhật có phải là hình vuông không
*/

    bool check_square() {
        return length == width;
    }
};

int main() {
    // Tạo một đối tượng hình chữ nhật
    std::cout<<"initial two side retangle"<<std::endl;
    rectangle rec0;

    // Tính chu vi
    float pri = rec0.caculate_primeter();
    std::cout << "primeter of retangle: " << pri<< std::endl;

    // Tính diện tích
    float area = rec0.caculate_area();
    std::cout << "area of retangle: " << area << std::endl;

    // Tính đường chéo
    float dia_line = rec0.caculate_diagonal_line();
    std::cout << "length of dia line: " << dia_line << std::endl;

    // Kiểm tra xem có phải hình vuông hay không
    bool is_square = rec0.check_square();
    if (is_square) {
        std::cout << "it is a square" << std::endl;
    } else {
        std::cout << "it is not a square" << std::endl;
    }

    return 0;
}