class menu
{
private:
	void bubbleSort(double arr[], size_t n);
	void insertion_sort(const char** arr, int n);
public:
	menu();
	uint16_t check_ID();
	void add_student();
	void update_student(uint16_t ID);
	void del_studen_by_ID(uint16_t ID);
	void find_student_by_ID(uint16_t ID);
	void find_student_by_name();
	void soft_student_by_GPA();
	void soft_student_by_name();
	void display_list_student();
};