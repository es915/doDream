#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int divisor(int num, int limit, int power) {
    int cnt=0, result=0;
    
    for (int i=1; i<=num/2; i++) {
        if (num%i==0) { // 10 -> 1 2 5
            cnt++; // 3
        }
    }
    
    result = ((cnt+1 > limit) ? power : cnt+1);
    return result;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for (int i=1; i<=number; i++) { // 기사단원 수 만큼 반복
        answer += divisor(i, limit, power); 
    }
    
    return answer;
}
