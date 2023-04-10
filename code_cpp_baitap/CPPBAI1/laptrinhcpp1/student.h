class student
{
private:
    char student_name[20];
    char student_sex[7];
    uint16_t student_ID;
    uint16_t student_age;
    double student_score[3];// thứ tự điểm toán lý hóa
    char student_acdemic[11];
    void set_student_academic(const char* hocluc);// đánh giá học lực sinh vien khi có điểm trung bình 3 môn toán lý hóa
    void student_rate();
    //void student_init(const char* student_name_init,const char* student_sex_init,
    //   uint16_t student_ID_init, uint16_t student_age_init,
    //   double* student_score_init, const char* student_acdemic_init);
public:
    student();
    // ~student();
    void set_student_name();
    char* return_raw_name();
    void get_student_name();
    void set_student_sex();
    void get_student_sex();
    void set_student_age();
    void get_student_age();
    double student_GPA();
    void get_student_ID();
    uint16_t get_raw_student_ID();
    void set_student_score_one_subject_name();
    void set_student_score_full_subject_name();
    void get_student_score();
    void get_student_academic();//tinh truu tuong
    // void get_hoc_luc1();
};