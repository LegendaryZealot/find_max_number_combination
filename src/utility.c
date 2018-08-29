#include <stdio.h>
#include <stdlib.h>

#include "utility.h"

typedef int(cmp)(int,int);

int cmp_int(int a,int b);

int cmp_int_first_number(int a,int b);

void swip(int *a,int *b);

void quick_sort(int *array, int left, int right,cmp *function);

void append_int_to_string(char* target,int *target_size,char* buf,int val);

void largestNumber(int *array, size_t arrayLength, int numbers, char *result)
{
    cmp *function;
    function=&cmp_int;
    quick_sort(array,0,arrayLength-1,function);
    function=&cmp_int_first_number;
    quick_sort(array,0,numbers-1,function);
    result=alloca(4*numbers);
    if(NULL==result)
    {
        //handle error here
        return;
    }
    int *current=array;
    int current_index=numbers;
    char buf[4];
    int result_index=0;
    while(current_index>0)
    {
        append_int_to_string(result,&result_index,buf,*current);
        current++;
        current_index--;
    }
    printf("max number:%s\n",result);
}

int cmp_int(int a,int b)
{
    if(a>b)
    {
        return 1;
    }
    if(a<b)
    {
        return -1;
    }
    return 0;
}

int cmp_int_first_number(int a,int b)
{
    while(a>=10)
    {
        a=a/10;
    }
    while(b>=10)
    {
        b=b/10;
    }
    return cmp_int(a,b);
}

void swip(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int *array, int left, int right,cmp *function)
{
    if(left>right)
    {
        return;
    }
    int i=left;
    int j=right;
    while(i!=j){
        while((0>=function(array[j],array[left]))&&i<j)
        {
            j--;
        }
        while((0<=function(array[i],array[left]))&&i<j)
        {
            i++;
        }
        if(i<j)
        {
            swip(&array[i],&array[j]);
        }
    }
    swip(&array[left],&array[i]);
    quick_sort(array, left, i - 1,function);
    quick_sort(array, i + 1, right,function);
}

void append_int_to_string(char* target,int *target_size,char* buf,int val)
{
    int bit=0;
    while(val>=10)
    {
        buf[bit++]=val%10+'0';
        val=val/10;
    }
    if(val>0)
    {
        buf[bit++]=val+'0';
    }
    for(int i=0;i<bit;i++)
    {
        target[*target_size+i]=buf[bit-i-1];
    }
    *target_size=*target_size+bit;
    target[*target_size]='\0';
}