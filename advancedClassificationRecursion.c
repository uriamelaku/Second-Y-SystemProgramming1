#include "NumClass.h"



int help_isPalindrome(int reverse, int temp){
    if(temp==0)return reverse;
    reverse = reverse*10 + temp%10;
    return help_isPalindrome(reverse,temp/10);
}
int help_isArmstrong(int sum, int num, int digits){
    if(num==0)return sum;
    sum = sum + myPow(num%10, digits);
    num = num/10;
    return help_isArmstrong(sum, num, digits);
}

int isArmstrong(int num){
    int digits = countOfDigits(num);
    int sum = help_isArmstrong(0, num, digits);
    if(sum==num) return 1;
    return 0;
}
    
    

int isPalindrome(int num){
    int reverse = help_isPalindrome(0,num);
    if(reverse==num) return 1;
    return 0;
}

