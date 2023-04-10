#include <iostream> 
#include<vector>
#include"menu.h"
#include"student.h"
#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define display_list(x,y) x.get_student_##y();\
cout<<"\t";
using namespace std;
vector<student> list_student;
menu::menu()
{
   //vector<student> list_student;
}
uint16_t menu::check_ID()
{
    uint16_t in_ID=0;
    cout << "in put ID: ";
    cin >> in_ID;
    for (uint16_t s = 0;s < list_student.size();s++)
    {
        if (in_ID == list_student[s].get_raw_student_ID())
        {
            return in_ID;
            break;
        }
    }
    cout << "in put ID error!!";
    return 0;
}
void menu::add_student()
{
    student st;
    st.set_student_name();
    st.set_student_age();
    st.set_student_sex();
    st.set_student_score_full_subject_name();
    list_student.push_back(st);
}
void menu::update_student(uint16_t ID)
{
    const uint16_t error_case=4;
    uint16_t update_student_check_case=error_case;
    student student_update;
    if (ID != 0)
    {
        student_update=list_student[ID-100];
        cout<<"select option:\n0:update student_name\n";
        cout<<"1:update student_agecout\n2:update student_sex\n";
        cout<<"3:update studentscore\n";
        cin>>update_student_check_case;
        switch (update_student_check_case)
        {
            case 0:
                student_update.set_student_name();
                break;
            case 1:
                student_update.set_student_age();
                break;
            case 2:
                student_update.set_student_sex();
                break;
            case 3:
                student_update.set_student_score_one_subject_name();
                break;
            default:
            cout<<"error select\n";
                break;
        }
        if(update_student_check_case!=0)
        {
            list_student[ID]=student_update;
        }
    }
}
void menu::del_studen_by_ID(uint16_t ID)
{
    if(ID!=0)
    {
        list_student.erase(list_student.begin()+ (ID- (uint16_t)100));
        cout<<"student ID: ";
        cout<< ID;
        cout<<" deleted\n";
    }
}
void menu::find_student_by_ID(uint16_t ID)
{
    if(ID!=0)
    {
        cout<<"------------------------------------------------------------\n";
        cout<<"|ID\t|name\t|age\t|sex\t|M\t|P\t|C\t|A\t|\n";
        display_list(list_student[ID-100],ID);
        display_list(list_student[ID-100],name);
        display_list(list_student[ID-100],age);
        display_list(list_student[ID-100],sex);
        display_list(list_student[ID-100],score);
        display_list(list_student[ID-100],academic);
        cout<<"|\n";
        cout<<"------------------------------------------------------------\n";
    }
}
void menu::find_student_by_name()
{
    uint8_t check_name =0,one_acess=0;
    char input_name[20]="\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    cout << "in put name: ";
    cin >> input_name;
    for(student student: list_student)
    {
        if(strcmp(student.return_raw_name(),input_name)==0)
        {  if(one_acess==0)
            {
                cout<<"------------------------------------------------------------\n";
                cout<<"|ID\t|name\t|age\t|sex\t|M\t|P\t|C\t|A\t|\n";
            }
            display_list(student,ID);
            display_list(student,name);
            display_list(student,age);
            display_list(student,sex);
            display_list(student,score);
            display_list(student,academic);
            check_name=1;
            one_acess=1;
            cout<<"|\n";
        }
        else
        {
            continue;
        }
    }
    if(check_name==1)
    {
        cout<<"------------------------------------------------------------\n";
    }
    else
    {
        cout<<"not find name in list student\n";
    }
}
void menu::bubbleSort(double arr[], size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void menu::soft_student_by_GPA()
{
    double check_value_GPA=0.0;
    const uint16_t size_arr= 100;
    uint16_t once_acces = 0;
    double array_value_GPA[size_arr] = { 0 };
    for (int f = 0;f < list_student.size();f++)
    {
        array_value_GPA[f] = list_student[f].student_GPA();
    }
    bubbleSort(array_value_GPA, list_student.size());
    for (int f = 0;f < list_student.size();f++)
    {
        for (int ff = 0;ff < list_student.size();ff++)
        {
            if (array_value_GPA[f] == list_student[ff].student_GPA())
            {
                if (once_acces == 0)
                {
                    cout << "------------------------------------------------------------\n";
                    cout << "|ID\t|name\t|age\t|sex\t|M\t|P\t|C\t|A\t|\n";
                }
                    display_list(list_student[ff], ID);
                    display_list(list_student[ff], name);
                    display_list(list_student[ff], age);
                    display_list(list_student[ff], sex);
                    display_list(list_student[ff], score);
                    display_list(list_student[ff], academic);
                    cout << "|\n";
                    once_acces = 1;
                    break;
            }
        }

    }
    if(once_acces ==1)
        cout << "------------------------------------------------------------\n";
}
void menu::insertion_sort(const char** arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        const char* key = arr[i];
        int j = i - 1;

        while (j >= 0 && strcmp(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void menu::soft_student_by_name()
{
    //double check_value_name = 0.0;
    uint16_t size_arr = (uint16_t)list_student.size();
    uint16_t once_acces = 0;
    const char *array_value_name[100] ;
    for (int f = 0;f < list_student.size();f++)
    {
        array_value_name[f]= list_student[f].return_raw_name();
    }
    insertion_sort(array_value_name, list_student.size());
    for (size_t f = 0;f < list_student.size(); f++)
    {
        for (size_t ff = 0;ff < list_student.size();ff++)
        {
            if (strcmp(list_student[ff].return_raw_name(),array_value_name[f])==0)
            {
                if (once_acces == 0)
                {
                    cout << "------------------------------------------------------------\n";
                    cout << "|ID\t|name\t|age\t|sex\t|M\t|P\t|C\t|A\t|\n";
                }
                display_list(list_student[ff], ID);
                display_list(list_student[ff], name);
                display_list(list_student[ff], age);
                display_list(list_student[ff], sex);
                display_list(list_student[ff], score);
                display_list(list_student[ff], academic);
                cout << "|\n";
                once_acces = 1;
            }
        }
    }
    cout << "------------------------------------------------------------\n";
}
void menu::display_list_student()
{
    cout<<"------------------------------------------------------------\n";
    cout<<"|ID\t|name\t|age\t|sex\t|M\t|P\t|C\t|A\t|\n";
    for(student student: list_student)
    {
        display_list(student,ID);
        display_list(student,name);
        display_list(student,age);
        display_list(student,sex);
        display_list(student,score);
        display_list(student,academic);
        cout<<"|\n";
    }
    cout<<"------------------------------------------------------------\n";
}
