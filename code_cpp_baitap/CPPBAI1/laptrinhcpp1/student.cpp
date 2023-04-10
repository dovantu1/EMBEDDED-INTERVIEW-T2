#include <iostream> 
#include"student.h"
#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define input_infomations(x,f) cout<<x;\
cin>>f;
#define out(x) cout<<x;
#define in(x) cin>>x;
using namespace std;
enum enum_student_score { math, physical, chemistry };
student::student()
{
    static uint8_t id = 100;
    student::student_ID = id;
    strcpy_s(student::student_name, "NONE");
    strcpy_s(student::student_sex, "NONE");
    student::student_age = 1;
    student::student_score[0] = 0;// thứ tự điểm toán lý hóa
    student::student_score[1] = 0;// thứ tự điểm toán lý hóa
    student::student_score[2] = 0;// thứ tự điểm toán lý hóa
    strcpy_s(student::student_acdemic, "NONE");
    id++;
}
void student::set_student_name()// ham nhap ten student
{
    bool valid = false;
    const uint16_t size_array = 100;
    char student_name[size_array]={'\0'};
    uint16_t length=0;
    out("NOTE=====>>input is character string<<=====");
    out(endl);
    input_infomations("input student name: ", student_name);
    for (length = 0;length < size_array;length++)
    {
        if(student_name[length]=='\0') break;
    }
    if (length > sizeof(student::student_name) / sizeof(student::student_name[0]));
   else
   {
        for (auto c:student_name)
        {
            if ((c >('@') && c < ('[')) || (c >('`') 
                && c < ('}')) || c == ' ' || c == '\0')
            {
                valid = true;
            }
            else
            {
                valid = false;
                break;
            }
        }
    }
    if (valid == false)
    {
        out("error input student name");
        out(endl);
    }
    else
    {
        for (auto i = 0;i < sizeof(student::student_name) / sizeof(student::student_name[0]);i++)
        {
            student::student_name[i] = student_name[i];
        }
    }
}
char* student::return_raw_name()
{
    return student_name;
}
void student::get_student_name()// ham doc ten student
{
    // out("student name: ");
    out("|");
    out(student_name);
    // out(endl);
}
void student::set_student_sex()
{
    const uint16_t error_student_sex = 3;
    uint16_t code_student_sex = error_student_sex;
    enum st_sex { m, fm, o };
    out("NOTE=====>>male: ")
    out(m);
    out("\tfemale: ");
    out(fm);
    out("\tother : ");
    out(o);
    out("<<=====");
    out(endl);
    input_infomations("input student sex: ", code_student_sex);
    if (code_student_sex == m)
    {
        strcpy_s((student::student_sex), "male  ");
    }
    else if (code_student_sex == fm)
    {
        strcpy_s(student_sex, "female");
    }
    else if (code_student_sex == o)
    {
        strcpy_s(student_sex, "other ");
    }
    else
    {
        out("error print input student sex");
        out(endl);
    }
}
void student::get_student_sex()
{
    // out("student sex: ");
    out("|");
    out(student_sex);
    // out(endl);
}
void student::set_student_age()// ham nhap ten student
{
    const uint16_t MAX_AGE = 100;
    const uint16_t MIN_AGE = 0;
    uint16_t student_age = 0;// do không nhập trực tiếp đc nên dùng 1 biến phụ để nhập tuổi 
    out("NOTE=====>>0<student age<100<<=====");
    out(endl);
    input_infomations("input student age: ", student_age);
    if (student_age > MAX_AGE || student_age < MIN_AGE)
    {
        out("error student age");
        out(endl);
    }
    else
    {
        student::student_age = student_age;
    }
}
void student::get_student_age()// ham doc ten student
{
    // out("student_age: ");
    out("|");
    out(student_age);
    // out(endl);
}
uint16_t student::get_raw_student_ID()
{
    return student_ID;
}
void student::get_student_ID()// ham doc ID student
{
    // printf("ID student: ");
    out("|");
    out(student_ID);
    // out(endl);
}
void student::set_student_score_one_subject_name()// nhap ten mon hoc va nhap diem 
{
    const double MAX_SCORE = 10.0, MIN_SCORE = 0.0;
    const uint16_t ERROR_CODE = 3;
    uint16_t subject_name = ERROR_CODE;
    double student_score[3] = { 0,0,0 };
    out("NOTE=====>>math:0\tphysical:1\tchemistry:2<<=====");// chú thích nhập tên môn học
    out(endl);
    input_infomations("input code subject: ",subject_name);
    switch (subject_name)
    {
    case math:
        input_infomations("input math score: ",student_score[math]);
        if (student_score[math] > MAX_SCORE && (student_score[math] < MIN_SCORE))
        {
            out("error input  math score");
            out(endl);
        }
        else
        {
            student::student_score[math] = student_score[math];
        }
        break;
    case physical:
        input_infomations("input physical score: ",student_score[physical]);
        if (student_score[physical] > MAX_SCORE && (student_score[physical] < MIN_SCORE))
        {
            out("error input  physical score");
            out(endl);
        }
        else
        {
            student::student_score[physical] = student_score[physical];
        }
        break;
    case chemistry:
        input_infomations("input chemistry score: ",student_score[chemistry]);
        if (student_score[chemistry] > MAX_SCORE && (student_score[chemistry] < MIN_SCORE))
        {
            out("error input chemistry score");
            out(endl);
        }
        else
        {
            student::student_score[chemistry] = student_score[chemistry];
        }
        break;
    default:
        out("error code subject");
        out(endl);
        break;
    }
}
void student::set_student_score_full_subject_name()//nhap diem toan bo mon hoc(toan ly hoa)
{
    out("NOTE=====>1<input object score<10<=====");
    out(endl);
    input_infomations("input math score: ",(student::student_score[0]));
    while (student_score[0] > 10 || student_score[0] < 0)
    {
        input_infomations("input again math score: ",(student::student_score[0]));
    }
    input_infomations("input physical score: ",(student::student_score[1]));
    while (student_score[1] > 10 || student_score[1] < 0)
    {
        input_infomations("input again physical score: ",(student::student_score[1]));
    }
    input_infomations("input chemistry score: ",(student::student_score[2]));
    while (student_score[2] > 10 || student_score[2] < 0)
    {
        input_infomations("input again chemistry score: ",(student::student_score[2]));
    }
}
void student::get_student_score()
{
    // out("math: ");
    out("|");
    out(student::student_score[math]);
    out("\t");
    out("|");
    // out("\tphysical: ");
    out(student::student_score[physical]);
    out("\t");
    out("|");
    // out("\tchemistry:  ");
    out(student::student_score[chemistry]);
    // out(endl);
}
double student::student_GPA()
{
    return (student_score[0] + student_score[1] + student_score[2]) / 3;// trả về điểm trung bình 3 môn toán lý hóa
}
void student::set_student_academic(const char* student_acdemic)
{
    strcpy_s(student::student_acdemic, "          ");// xóa học lực set lại tránh trường hợp đọc kết quả là "gioig binh"
    strcpy_s(student::student_acdemic, student_acdemic);
}
void student::student_rate()
{
    // double diem_trung_binh=0;// them một biến để nhận kết quả trả về từ hàm điểm trung bình
    // diem_trung_binh=student::diem_trung_binh();
    // đặt điều kiện để dánh giá sinh viên
    const double A = 8.0, B = 6.5, C = 5;
    double get_score = student_GPA();
    if (get_score >= A)
    {
        set_student_academic("A");
    }
    else if (get_score >= B)
    {
        set_student_academic("B");
    }
    else if (get_score >= C)
    {
        set_student_academic("C");
    }
    else
    {
        set_student_academic("D");
    }
}
void student::get_student_academic()
{
    // char * h=student::hocluc
    student_rate();
    // return student_acdemic;
    // out("studen academic: ");
    out("|");
    out(student::student_acdemic);
    // out(endl);
}