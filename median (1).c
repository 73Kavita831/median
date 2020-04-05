#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int *quicksort(int number[100],int first,int last)
{
    int i,j,pivot,temp;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(number[i]<=number[pivot] && i<last)
                i++;
            while(number[j]>number[pivot])
                j--;
            if(i<j)
            {
                temp=number[i];
                number[i]=number[j];
                number[j]=temp;
            }
        }
        temp=number[pivot];
        number[pivot]=number[j];
        number[j]=temp;
        quicksort(number,first,j);
        quicksort(number,j+1,last);
    }
    return number;
}
int main(int argc, char *argv[])
{
if(argc < 3)
{
printf("compile : gcc median.c -o median\n");
printf("run : ./median <number of elements> <enter the elements>\n");
return(1);
}
int i,j,count,number[100],*p, mid;
count= atoi(argv[1]);
j=2;
for(i=0;i<count;i++)
{
number[i] = atoi(argv[j]);
j+=1;
}
if(count%2!=0)
    {
    p = quicksort(number,1,count);
    mid =(count+1)/2;
    printf("The median is: ");
    printf( "%d\n",*(p + mid));
    return 0;
    }
else
    {
    printf("exit");
    }
}
