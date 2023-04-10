#include<stdio.h>
#include<stdint.h>
#define u32  int32_t
#define u8  uint8_t
u8 arr[] ="The Grammy award-winning singer. Who has been less active on digital platforms in recent weeks. Explained her decision to distance herself from social media platforms during an appearance on the Conan OBrien Needs a Friend podcast, alongside her brother Finneas";
u8 arr_lower[]="xin chao! chung toi den tu sao hoa, ban den tu dau? chuc ban 1 ngay tot lanh. hen gap lai ban sau nhe";
//Cau 1: Viet mot chuyen dao nguoc VD: "Finneas brother her alongside .... Grammy The"
//cau 2: In Hoa chu cai dau tien sau dau cham
//Cau 3: Chuyen doi tat ca doan van thanh chu thuong
//Cau 4: Chuyen doi tat ca doan van thanh chu hoa
// TIME CODE (3H) BY DO VAN TU
void fuction_convert(u8 *arr,u32 _size) 
{
    u32 i=0,i2=_size-2,i3=0,i4=0;
    u8 arr_tem[_size];
    for(i=_size-2;i>=0;i--)
    {
        if(arr[i]==' ')
        {
            for(i3=i+1;i3<=i2;i3++)
            {
                arr_tem[i4]=arr[i3];
                i4++;
            }
            if(arr[i-1]=='!'||arr[i-1]==','||arr[i-1]=='?'||arr[i-1]=='?')
            {
                arr_tem[i4]=arr[i-1];
                i2=i-2;
                i--;
                i4++;
                arr_tem[i4]=' ';
                i4++;
            }
            else
            {
                arr_tem[i4]=' ';
                i4++;
                i2=i-1;
            }
        }
    }
    i=0;
    while(arr[i]!=' ')
    {
        arr_tem[i4]=arr[i];
        i4++;
        i++;
    }
    arr_tem[_size-1]=0;
    i4=0;
    for(i=0;i<_size-1;i++)
    {
        arr[i]=arr_tem[i];
    }
}
u8 check_if_letter(u8 input)
{
    u8 a,b=0 ;
    for(a=97;a<123;a++)
    {
        if(input==a) 
        {
            b=1;
            break;
        }
    }
    return b;
}
u8 check_if_upper(u8 input)
{
    u8 a,b=0 ;
    for(a=65;a<90;a++)
    {
        if(input==a) 
        {
            b=1;
            break;
        }
    }
    return b;
}
void fuction_upper(u8 *arr,u32 _size)// size nhỏ hơn 255 lớn chỉnh lại 
{
    u32 i=0,i2=_size-2,i3=0,i4=0;
    u8 arr_tem[_size];
    if(check_if_letter(arr[0]))
    {
        arr_tem[0]=arr[0]-(uint8_t)32;
    }
    else{
        arr_tem[0]=arr[0];
    }
    for(i=1;i<_size-1;i++)
    {
        if(arr[i]=='!'||arr[i]=='?'||arr[i]=='.')
        {
            if(check_if_letter(arr[i+2]))
            {
                arr_tem[i]=arr[i];
                arr_tem[i+1]=arr[i+1];
                arr_tem[i+2]=arr[i+2]-(uint8_t)32;
            }
            i++;
            i++;
        }
        else
        {
            arr_tem[i]=arr[i];
        }
    }
    for(i=0;i<_size-1;i++)
    {
        arr[i]=arr_tem[i];
    }
}
void fuction_convert_all_lower(u8 *arr,u32 _size)
{
    u8 a,b=0 ;
    u8 arr_tem[_size];
    for(a=0;a<_size-1;a++)
    {
        if(check_if_upper(arr[a]))
        {
            arr_tem[a]=arr[a]+(u8)32;
        }
        else
        {
            arr_tem[a]=arr[a];
        }
    }
    for(a=0;a<_size-1;a++)
    {
        arr[a]=arr_tem[a];
    }
}
void fuction_convert_all_upper(u8 *arr,u32 _size)
{
    u8 a,b=0 ;
    u8 arr_tem[_size];
    for(a=0;a<_size-1;a++)
    {
        if(check_if_letter(arr[a]))
        {
            arr_tem[a]=arr[a]-(u8)32;
        }
        else
        {
            arr_tem[a]=arr[a];
        }
    }
    for(a=0;a<_size-1;a++)
    {
        arr[a]=arr_tem[a];
    }
}
int main(void)
{
    // printf("chu thuong: %c, chu hoa: %c\n", 'a', 'a'-32);
    // printf("chu thuong: %c, chu hoa: %c\n", 'i', 'i'-32);
    // printf("chu thuong: %d, chu hoa: %d\n", 'e', 'E');
    u32 i;
    printf("chuoi mau chua xu ly!!!\n");
    for(i=0;i<sizeof(arr)/sizeof(arr[i]);i++)
    {
        printf("%c",arr[i]);
    }
    printf("\n");
    printf("\n");
    printf("dao nguoc tu trong cau!!!\n");
    fuction_convert(arr,sizeof(arr)/sizeof(arr[0]));
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        printf("%c",arr[i]);
    }
    printf("\n");
    printf("\n");
    printf("chuoi mau chua xu ly(1)!!!\n");
    for(i=0;i<sizeof(arr_lower)/sizeof(arr_lower[i]);i++)
    {
        printf("%c",arr_lower[i]);
    }
    printf("\n");
    printf("\n");
    printf("viet hoa sau dau cham....!!!\n");
    fuction_upper(arr_lower,sizeof(arr_lower)/sizeof(arr_lower[0]));
    for(i=0;i<sizeof(arr_lower)/sizeof(arr_lower[0]);i++)
    {
        printf("%c",arr_lower[i]);
    }
    printf("\n");
    printf("\n");
    printf("viet ki tu thuong...!!!\n");
    fuction_convert_all_lower(arr_lower,sizeof(arr_lower)/sizeof(arr_lower[0]));
    for(i=0;i<sizeof(arr_lower)/sizeof(arr_lower[0]);i++)
    {
        printf("%c",arr_lower[i]);
    }
    printf("\n");
    printf("\n");
    printf("viet ki tu hoa...!!!\n");
    fuction_convert_all_upper(arr_lower,sizeof(arr_lower)/sizeof(arr_lower[0]));
    for(i=0;i<sizeof(arr_lower)/sizeof(arr_lower[0]);i++)
    {
        printf("%c",arr_lower[i]);
    }
    printf("\n");
    printf("\nthank you\n");
    return 0;
}
