#include "NumClass.h"



int isArmstrong(int num){
    int digits = countOfDigits(num);
    int temp = num;
    int sum =0;
    while(temp!=0){
        sum = sum +(int)(myPow(temp%10,digits));
        temp = temp/10;
    }
    if(sum==num) return 1;
    return 0;

}

int isPalindrome(int num){
    int temp = num;
    int reversed = 0;

    while (temp!=0) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }

    if(num == reversed) return 1;
    return 0;
}