#include<stdio.h>
#define u32 unsigned int
#define u8 unsigned char
//copyright by DOVANTU
u32 _scanf_num()
{
	u32 _num=0;// biến tạm cho giá trị nhập vào
	u8  i=0;
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("Hi, let's goooooooooooooooooooooooooo\n");
	for(;;)
	{
		printf("Number input: ");
		scanf("%d",&_num);
        // giá trị không lớn hơn 7 chữ số
        // sai nhập lại
		if(_num>9999999)
		{
			printf("Number input is error format]\n");
			printf("0=<Number input<9999999\n");
		}
		else
		{
			printf("Read your number is:\n");
			break;
		}
	}
    // sử dụng riêng cho trường hợp số nhập vào bằng 0
    if(_num==0)
    {
        printf("KHONG");
    }
    return _num;
}
void handle_OneNumTStr(u8 One_num_in)//hàm đổi chữ ra số cơ bản 
{
	switch (One_num_in)
	{
		case 9: printf("CHIN ");
		break;
		case 8: printf("TAM ");
		break;
		case 7: printf("BAY ");
		break;
		case 6: printf("SAU ");
		break;
		case 5: printf("NAM ");
		break;
		case 4: printf("BON ");
		break;
		case 3: printf("BA ");
		break;
		case 2: printf("HAI ");
		break;
		case 1: printf("MOT ");
		break;
		case 0: printf("KHONG ");
		break;
		break;
	}
}
void hundreds(u8 hundreds_in)// hàm đổi chữ ra số kèm đơn vị trăm
{   
    handle_OneNumTStr(hundreds_in);
    printf("TRAM ");
}
void tens(u8 tens_in)
{
    switch (tens_in)
    {
    case 1:
        printf("MUOIF ");// phân biệt mười và mươi nếu 15 11 10 sẽ dùng trường hợp này
        break;
    case 0:
        ;
        break;
    default:
        handle_OneNumTStr(tens_in);// đổi chữ ra số kèm đơn vị chục(mươi)
        printf("MUOI "); 
        break;
    }
}
void units(u8 tens_in,u8 units_in)//hàm đổi số ra chữ hàng đơn vị
{
    if(units_in==5&&tens_in>0)//tạo trường hợp đọc là lăm vd 15 đọc mười lăm, đọc là 5
    {
        printf("LAM ");
    }
    else if(units_in==1&&tens_in>1)
    {
        printf("MOT ");
    }
    else if(units_in==0)// nếu đơn vị bằng 0 thì không làm gì vì đã được xử lý ở hàm có đơn vị lớn hơn
    // ví dụ 20 đọc hai mươi=>đúng, không cần thêm không thành hai mươi không =>sai
    {
        ;
    }
    else
    {
        handle_OneNumTStr(units_in);//không thuộc trường hợp trên thì in ra chữ đọc từ số của hàng đơn vị,vd  22=> hai
    }
}
void handle_7NumTStr()
{
    u32 num_scanf=0,num_scanf1=0;
    u8 tem_retur_arr_num[7]={0,0,0,0,0,0,0},
    i=0;
    num_scanf=_scanf_num();
    num_scanf1=num_scanf;
    //tách số theo từng đơn vị và đưa vào mảng 
    while (i<7)
    {
        tem_retur_arr_num[i]=num_scanf%10;
        num_scanf/=10;
        i++;
    }
    // i=0;
    // while (i<7)
    // {
    //    	printf("%d",tem_retur_arr_num[6-i]);
    //     i++;
    // }
    printf("\n");
    if(tem_retur_arr_num[6]!=0)
    {
        units(0,tem_retur_arr_num[6]);
        printf("TRIEU ");
    }
    if(tem_retur_arr_num[3]!=0||tem_retur_arr_num[4]!=0||tem_retur_arr_num[5]!=0)
    {
         if(num_scanf1>99999)
        {
            hundreds(tem_retur_arr_num[5]);
        }
        if(num_scanf1>99999&&tem_retur_arr_num[3]>0&&tem_retur_arr_num[4]==0)
        {
            printf("LINH ");
        }
        else
        {
         tens(tem_retur_arr_num[4]);
        }
        units(tem_retur_arr_num[4],tem_retur_arr_num[3]);
        printf("NGHIN ");
    }
    if(tem_retur_arr_num[2]!=0||tem_retur_arr_num[1]!=0||tem_retur_arr_num[0]!=0)
    {   
        if(num_scanf1>99)
        {
            hundreds(tem_retur_arr_num[2]);
        }
        if(num_scanf1>99&&tem_retur_arr_num[0]>0&&tem_retur_arr_num[1]==0)
        {
            printf("LINH ");
        }
        else
        {
         tens(tem_retur_arr_num[1]);
        }
        units(tem_retur_arr_num[1],tem_retur_arr_num[0]);
    }
	printf("\nend,goodbye");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
}
int main()
{
    handle_7NumTStr();
	return 0;
}