#include <stdio.h>
#include <stdlib.h>


void checkOddEven(int number){
    if((number % 2) == 0 ){
        printf("Number %d is even",number);
    }
    else{
        printf("Number %d is odd",number);
    }
}
int main()
{
    int number = 0;
    printf("Enter a number:");
    scanf("%d",&number);
    checkOddEven(number);
    return 0;
}
