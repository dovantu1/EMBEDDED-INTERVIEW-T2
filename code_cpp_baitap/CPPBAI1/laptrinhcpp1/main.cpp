#include<iostream>
#include<string>
#include<vector>
#include"student.h"
#include"menu.h"
#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define out(x) cout<<x;
#define in(x) cin>>x;
using namespace std;
int main(int argc, char const* argv[])
{
    menu menu;
    const uint16_t error = 9;
    uint16_t select_otp = error;
    enum enum_slect_otp
    {
        add_student=1, update_student, del_studen_by_ID, find_student_by_ID,
        find_student_by_name, soft_student_by_GPA, soft_student_by_name, display_list_student
    };
    while(1)
    {
        cout << "input number to select!!!\n";
        cout << "1: add_student\n";
        cout<< "2: update_student\n";
        cout<< "3: del_studen_by_ID\n";
        cout<< "4: find_student_by_ID\n";
        cout<< "5: find_student_by_name\n";
        cout<< "6: soft_student_by_GPA\n";
        cout<< "7: soft_student_by_name\n";
        cout<< "8: display_list_student\n";
        cin >> select_otp;
        switch (select_otp)
        {
            case add_student :
                menu.add_student();
                break;
            case update_student:
                menu.update_student(menu.check_ID());
                break;
            case del_studen_by_ID:
                menu.del_studen_by_ID(menu.check_ID());
                break;
            case find_student_by_ID:
                menu.find_student_by_ID(menu.check_ID());
                break;
            case find_student_by_name:
                menu.find_student_by_name();
                break;
            case soft_student_by_GPA:
                menu.soft_student_by_GPA();
                break;
            case soft_student_by_name:
                menu.soft_student_by_name();
                break;
            case display_list_student:
                menu.display_list_student();
                break;
            default:
                cout << "error option!!!";
                break;
        }
    }
    return 0;
}
