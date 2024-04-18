#include <stdio.h>

// 쉘 정렬 함수
void shellSort(int arr[], int n) {
    // 간격(gap) 설정
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 삽입 정렬 수행
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// 배열을 출력하는 함수
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 메인 함수
int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("정렬 전 배열: ");
    printArray(arr, n);

    shellSort(arr, n);

    printf("정렬 후 배열: ");
    printArray(arr, n);

    return 0;
}
