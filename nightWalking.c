#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// scope_rows는 2차원 배열 scope의 행 길이, scope_cols는 2차원 배열 scope의 열 길이입니다.
// times_rows는 2차원 배열 times의 행 길이, times_cols는 2차원 배열 times의 열 길이입니다.
int solution(int distance, int** scope, size_t scope_rows, size_t scope_cols, int** times, size_t times_rows, size_t times_cols) {
    int answer = distance;
    
    for (int i=0; i<scope_rows; i++) {
        if (scope[i][0]>scope[i][1]) {
            int tmp = scope[i][0];
            scope[i][0] = scope[i][1];
            scope[i][1] = tmp;
        }
    }
    
    
    for(int i=0; i<scope_rows; i++) {
        int tt = times[i][0] + times[i][1]; // 2 + 5
        for (int j=scope[i][0]; j<=scope[i][1]; j++) { // 3 부터 4까지
            int div = j%tt;
            if (((div<=times[i][0])&&(div>0)) && (answer > j)) { // 
                answer = j;
            }
        }
    }
    return answer;
}
