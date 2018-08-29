#include <stdio.h>
#include <stdlib.h>

#include "utility.h"
#include "define.h"

int main(int argc, char const *argv[])
{
    size_t arrayLength;
    int numbers;
    int *array;
    char *result=NULL;
    printf("input the arrayLength:");
    if(1!=scanf("%lu",&arrayLength))
    {
        //handle input error here
        return 0;
    }
    printf("input the numbers:");
    if(1!=scanf("%d",&numbers))
    {
        //handle input error here
        return 0;
    }
    if((numbers>arrayLength)|(numbers<=0))
    {
        //handle input error here
        return 0;
    }
    if(NULL==(array=malloc(sizeof(int)*arrayLength)))
    {
        //handle malloc error here
        return 0;
    }
    for(int i=0;i<arrayLength;i++)
    {
        printf("input the number of array[%d]:",i);
        if(1!=scanf("%d",&array[i]))
        {
            //handle input error here
            return 0;
        }
    }
    largestNumber(array,arrayLength,numbers,result);
    free(array);
    return 0;
}
