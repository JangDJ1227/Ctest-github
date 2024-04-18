#include <stdio.h>

// 버블 정렬 함수
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        // 배열의 끝까지 반복
        for (j = 0; j < n - i - 1; j++) {
            // 현재 요소와 다음 요소를 비교하여 정렬
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 배열을 출력하는 함수
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 메인 함수
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("정렬 전 배열: ");
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    printf("정렬 후 배열: ");
    printArray(arr, n);
    
    return 0;
}
