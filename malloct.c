#include <stdio.h>
#include <stdlib.h>
int main() {
  // 用來管理動態記憶體的指標
    int *dynArr;
    // 指定空間大小
    int arrLen = 10;
    // 取得記憶體空間
    dynArr = malloc( arrLen * sizeof(int) );
    printf("%p\n",dynArr);
    if( dynArr == NULL ) {
        // 無法取得記憶體空間
    fprintf(stderr, "Error: unable to allocate required memory\n");
        return 1;
    }
    // 使用動態取得的記憶體空間
    int i;
    for (i = 0; i < arrLen; ++i) {
        dynArr[i] = i;
        printf("%p\n", &dynArr[i]);
        printf("%d\n", dynArr[i]);
    }

    // 釋放記憶體空間
    free(dynArr);

    return 0;
}