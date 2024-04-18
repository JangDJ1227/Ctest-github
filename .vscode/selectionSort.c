#include <stdio.h>

// 선택 정렬 함수
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    // 배열 전체를 순회하며 최소값을 찾아 정렬
    for (i = 0; i < n - 1; i++) {
        // 현재 위치부터 배열 끝까지의 최소값을 찾음
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // 최소값을 현재 위치로 이동
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// 배열을 출력하는 함수
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 메인 함수
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("정렬 전 배열: ");
    printArray(arr, n);
    
    selectionSort(arr, n);
    
    printf("정렬 후 배열: ");
    printArray(arr, n);
    
    return 0;
}
