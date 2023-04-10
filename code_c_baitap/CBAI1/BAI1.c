#include <stdio.h>
#include<stdlib.h>
#include<time.h>	
#define struct_size 15// size struct 
// min max giá trị random
#define MIN_ 98
#define MAX_ 100

struct bai1{
	unsigned char size1;
	unsigned char *arr1;
};

struct bai1 struct1;

int randomA(int minN, int maxN){
 return minN + rand() % (maxN + 1 - minN);
}

void randomArray(struct bai1 *value, unsigned char length,unsigned char min,unsigned char max){
    srand((int)time(0));

    value->size1 = length;

    value->arr1 = (unsigned char *)malloc(sizeof(unsigned char)*value->size1);
    int r;
    for(int i = 0; i < value->size1; ++i){
        value->arr1[i] = randomA(min,max);
    }    
}

void arrange_array()
{
	unsigned char i=0,a=0,a1=0;
    /*
        a: biến gán vị trí phần tử(tạm gọi là phần tử arr[a]) của mảng đang xét(tạm gọi arr)
        a1: biến gán vị trí phần tử(tạm gọi là phần tử arr[a1]) của mảng đang xet(tạm gọi arr)
        i: biến trung gian để lưu giá trị khi gặp trường hợp phần tử tiếp theo của mảng lớn hơn phần tử mảng đang xét
        mô tả hoạt động:
            tạo vòng lặp for với giá trị a chạy từ đầu tiên đến vị trí sau cùng của mảng(arr)
            tạo 1 vòng lặp for tiếp theo a1 chạy từ vị trí đầu tiên tới vị trí sau cùng của mảng(arr)
            arr[a]<arr[a1]
            đảo giá trị 2 phần tử với nhau (sử dụng i)
            arr[a]>=arr[a1] không làm gì
    */
	for(a=0;a<struct1.size1;a++)
	{
		for(a1=0;a1<struct1.size1;a1++)
	{
		if(*(struct1.arr1+a)<*(struct1.arr1+a1))
		{
			i=*(struct1.arr1+a);
			*(struct1.arr1+a)=*(struct1.arr1+a1);
			*(struct1.arr1+a1)=i;
		}
	}
	}
    printf("\nket qua khi sap sep\n");
    // tiếp tục sử dụng biến a cho vòng lặp in các số trong mảng(arr) sau khi đã được sắp xếp
	for(a=0;a<struct1.size1;a++)
    {
        printf("arr[%d] = %d  \t\t",(a),*(struct1.arr1+a));
        if((a+1)%5==0)
        {
            printf("\n");
        }
    }
}

void repeat_array_0()
{//lưu ý cần sắp xếp khi sử dụng hàm này để tính số lần xuất hiện trong mảng
	unsigned char ss_0=0,dem=0,ss_1=0,ss_2=0;
	unsigned char tem_arr[struct_size*2];
/*
    ss_0: biến gán vị trí phần tử(tạm gọi là phần tử arr[a]) của mảng đang xét(tạm gọi arr)
    ss_1: biến gán vị trí phần tử(tạm gọi là phần tử arr[a1]) của mảng đang xet(tạm gọi arr)
    dem: biến đếm số lần phần tử mảng đang xét được lặp lại
    lấy giá trị phần tử mảng arr[ss_0] so sánh arr[ss_1]
    nếu arr[ss_0]==arr[ss_1]
    biến đếm tăng 1
*/
	for(ss_0=0;ss_0<struct1.size1;ss_0++)
	{ 
        //vòng lặp bắt đầu từ ss_0 nhằm tránh lặp lại các giá trị đã xét rồi 
		for(ss_1=ss_0;ss_1<struct1.size1;ss_1++)
		{
			if(*(struct1.arr1+ss_0)==*(struct1.arr1+ss_1))
			{
				dem++;
			}
		}
    //lưu phần tử và số lần xuất hiện
        tem_arr[ss_2]=*(struct1.arr1+ss_0);
        tem_arr[ss_2+1]=dem;
        ss_2+=2;
    //bỏ qua các phần tử giống nhau xét tiếp phần tử tiếp theo 
        ss_0=ss_0+dem-1;
		dem=0;
	}
    // xuất giá trị phần tử và số lần phần tử xuất hiện trong mảng,canh 1 hàng 3 cột để dễ quan sát
    ss_1=0;
	for(ss_0=0;ss_0<ss_2;ss_0+=2)
	{	
        printf("so\t%d\txuat hien\t%d\t",tem_arr[ss_0],tem_arr[ss_0+1]);
        if((ss_1+1)%3==0)
        {
            printf("\n");
        }
        ss_1++;
	}
}

void repeat_array_1()
{
    unsigned char   ss_0=0,
                    ss_1=0,
                    dem=0,
                    ss_2=0,
                    trung_lap=0;
	unsigned char tem_arr[struct_size*2];// mảng tạm để lưu số ,phần tử kế tiếp số lần xuất hiện của nó 
    /////////////////////////////////////////////////////////////////////////////////
	for(ss_0=0;ss_0<struct1.size1;ss_0++)
	{   
        if(ss_0==0);
        // không xét phần tử đầu tiên vì không có phần tử nào trước đó
        else
        {
            for(ss_1=ss_0;ss_1>0;)
            {
                ss_1--;
                if(*(struct1.arr1+ss_0)==*(struct1.arr1+ss_1))
                {
                    trung_lap=1;
                    break;
                }
            }
        }
        // nếu giá trị phần tử chưa được xét thì sẽ xét số lần phần tử xuất hiện trong mảng
        if(trung_lap==0)
        {
            for(ss_1=0;ss_1<struct1.size1;ss_1++)
            {
                if(*(struct1.arr1+ss_0)==*(struct1.arr1+ss_1))
                {
                    dem++;
                }
            }
            // lưu giá trị và số lần xuất hiện trong mảng vào 2 ô kế tiếp của mảng tạm
			tem_arr[ss_2]=*(struct1.arr1+ss_0);
			tem_arr[ss_2+1]=dem;
			ss_2+=2;
        }
        // reset biến đếm và trùng lặp (0 tức không trùng lặp)
		dem=0;
        trung_lap=0;
	}
    // xuất giá trị phần tử và số lần phần tử xuất hiện trong mảng,canh 1 hàng 3 cột để dễ quan sát
    ss_1=0;
	for(ss_0=0;ss_0<ss_2;ss_0+=2)
	{
		printf("so\t%d\txuat hien\t%d ||\t",tem_arr[ss_0],tem_arr[ss_0+1]);
        if((ss_1+1)%3==0)
        {
            printf("\n");
        }
        ss_1++;
	}
}

int main()
{
    unsigned char i;
	struct1.size1=struct_size;
	randomArray(&struct1, struct1.size1,MIN_,MAX_);
    // in ra các số trong mảng để đối chiếu
	// for (int i = 0; i < struct1.size1; i++)
    // {
    // printf("arr[%d] = %d  \t\t",i, struct1.arr1[i]);
	// 	if((i+1)%5==0)
	// 	{
	// 		printf("\n");
	// 	}
    // }
    printf("\ncach 2------------------------------------\n");
	repeat_array_1();
	arrange_array();
    printf("\ncach 1------------------------------------\n");
	repeat_array_0();
    printf("\n          the end");
	return 0;
}