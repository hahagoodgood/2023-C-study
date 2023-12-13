#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    // step1. 문자열을 입력받기 위해서 충분한 크기의 문자배열을 선언한다.
    char tmp[100];   // 충분한 공간을 확보하기 위한 임시문자배열을 선언한다.
    char* str[3];    // 동적 할당을 하기 위한 포인터 배열 변수를 선언한다.

    // step2. 문자열을 입력받는다.
    for (int i = 0; i < 3; i++) {
        strcpy(tmp, "test string");                                // gets() 함수는 입력하는 문자열 사이에 space가 가능하다.
        // step3. 입력받은 문자열의 크기를 계산한 후 그 공간만큼 동적할당 받는다.
        str[i] = (char*)malloc(strlen(tmp) + 1);   // malloc()이 주소를 반환해 주기 때문에 (char*)로 형식을 지정해 주어야 한다.
        // strlen()는 NULL 전까지 문자열 길이를 불러오기 때문에 '+1'을 하여 "문자열\n"로 만들어 준다.
        // 문자열 길이만큼만 저장하는 공간을 확보한다.
// step4. 할당받은 공간에 문자열을 대입한다.
        strcpy(str[i], "test string");                       // gets() 함수를 통해 입력받아 tmp에 저장한 문자열을 str[i]에 복사한다.
    }

    for (int i = 0; i < 3; i++)   // 입력된 문자열을 출력한다.
        printf("%s\n", str[i]);

    for (int i = 0; i < 3; i++)   // 할당받은 메모리(3개)를 반환시켜 준다.
        free(str[i]);

    //return 0; //==========================================================================================================================================

    char* list[10];
    
    for (int i = 0; i < 10; i++) {
        list[i] = (char*)malloc(100 * sizeof(char));
        if (list[i] == NULL) {
            printf("malloc() 실패\n\n");
            exit(1);
        }
        strcpy(list[i], "test string");
    }
    for (int i = 0; i < 10; i++) {
        printf("문자열 %d: %s\n", i, list[i]);
    }
    return 0;
}