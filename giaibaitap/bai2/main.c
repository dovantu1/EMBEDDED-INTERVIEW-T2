#include<stdio.h>
int arr[]={1,3,5,7,0};
int main()
{
    int f=0,h=0,tem=0,set=0,set2=0;
    for(f=0;f<sizeof(arr)/sizeof(arr[0]);f++)
    {
        for(h=0;h<=2;h++)
        {
            if(arr[f]%h==0)
            {
                // set2++;
                printf("value %d\n",set2);
            }
        }
        if(set2==2)
        {
            tem=arr[f];
            set=1;
            set2=0;
        }
        if(set==0)
        {
            tem=-1;
        }
    }
    printf("value %d\n",tem);
    return 0;
}