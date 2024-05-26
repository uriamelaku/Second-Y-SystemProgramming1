#include "NumClass.h"

int calculateFactorial(int num){
    int sum=1;
        for(int i=num;i>0;i--){
            sum= sum*i;
        }
    return sum;
}
int countOfDigits(int num){
    int temp = num;
    int digits=0;
    while(temp!=0){
        digits++;
        temp=temp/10;
    }
    return digits;
}
int myPow(int x, int y) {
    if (y == 0) {
        return 1;
    }
    int result = 1;
    while (y > 0) {
        result= result*x;
        y--;
    }
    return result;
}
//wikipedia
int mysqrt(double num) {

    double epsilon = 1e-6;
    double x = num / 2.0;

    while ((x * x - num) > epsilon || (num - x * x) > epsilon) {
        x = 0.5 * (x + num / x);
    }

    return (int)x;
}

int isStrong(int num){
    int temp=num;
    int sum=0;
    int digit;
    while (temp!=0)
    {
        digit = temp%10;
        sum = sum + calculateFactorial(digit);
        temp=temp/10;
    }

    if (sum==num) return 1;
    return 0;
    
}

int isPrime(int num){
    for (int i = 2; i <= mysqrt(num); i++) { 
        // if num is perfectly divisible by i
        if (num % i == 0) { 
            return 0; 
        } 
    } 
    return 1;
}