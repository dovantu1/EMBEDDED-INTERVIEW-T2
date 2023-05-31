/*
*File: animal.cpp
*Author: Do Van Tu
*Date: 27/05/2023
*Description: chương trình nhập vào chiều cao cân nặng tên loài vật, so sánh cân nặng
*chiều cao, so sánh tuổi giữa các loài vật, tính chỉ số BMI của chúng
*/

#include <iostream>
#include <string>

/*
*class: animal
*input: radius
*fuction: calculate_circumference,caculate_area
*output: none
*/

class animal {
private:
    std::string name;
    int age;
    float weight;
    float height;

public:

/*
*constructor: animal
*input:n(tên), a(tuổi), w(cân nặng), h(chiều cao)
*output:none
*description: khởi tạo các biến thông tin của một loài vật
*/

    animal(std::string n, int a, float w,float h) {
        name = n;
        age = a;
        weight = w;
        height = h;
    }

/*
*fuction: calculate_BMI
*input:none
*output:return calculate_BMI
*description: trả về giá trị tính hệ số BMI của 1 loài vật
*/

    float calculate_BMI() {
        float bmi = weight / (height * height);
        return bmi;
    }

/*
*fuction: compare_age
*input:otheranimal
*output:none
*description: so sánh tuổi 2 loài vật với nhau
*/

    void compare_age(animal otheranimal) {
        if (age < otheranimal.age) {
            std::cout << name << " is younger than " << otheranimal.name << std::endl;
        } else if (age > otheranimal.age) {
            std::cout << name << " is older than " << otheranimal.name << std::endl;
        } else {
            std::cout << name << " and " << otheranimal.name << " have the same age" << std::endl;
        }
    }

/*
*fuction: compare_weight
*input: otheranimal
*output: none
*description: so sánh tuổi 2 loài vật với nhau
*/

    void compare_weight(animal otheranimal) {
        if (weight < otheranimal.weight) {
            std::cout << name << " weighs less than " << otheranimal.name << std::endl;
        } else if (weight > otheranimal.weight) {
            std::cout << name << " weighs more than " << otheranimal.name << std::endl;
        } else {
            std::cout << name << " and " << otheranimal.name << " have the same weight" << std::endl;
        }
    }

};

int main() {
    std::string name;
    int age;
    float weight;
    float height;
std::cout<<"hllo"<<6/(0.2*0.2)<<std::endl;
    // nhập vào giá trị cho loài vật 1
    std::cout << "input the name of animal 1: ";
    std::cin >> name;
    std::cout << "input the age of animal 1: ";
    std::cin >> age;
    std::cout << "input the weight of animal 1: ";
    std::cin >> weight;
    std::cout << "input the height of animal 1: ";
    std::cin >> weight;

    animal animal1(name, age, weight, height);

    // nhập vào giá trị cho loài vật 2
    std::cout << "input the name of animal 2: ";
    std::cin >> name;
    std::cout << "input the age of animal 2: ";
    std::cin >> age;
    std::cout << "input the weight of animal 2: ";
    std::cin >> weight;
    std::cout << "input the height of animal 2: ";
    std::cin >> height;
    animal animal2(name, age, weight, height);

    // tính toán giá trị BMI
    float bmi1 = animal1.calculate_BMI();
    std::cout << "BMI of animal 1: " << bmi1 << std::endl;

    float bmi2 = animal2.calculate_BMI();
    std::cout << "BMI of animal 2: " << bmi2 << std::endl;

    // so sánh tuổi của chúng
    animal1.compare_age(animal2);

    // so sánh cân nặng của chúng
    animal1.compare_weight(animal2);

return 0;
}

