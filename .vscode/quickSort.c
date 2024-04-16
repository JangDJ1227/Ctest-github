#include <stdio.h>

// 배열의 두 요소를 교환하는 함수
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 분할 함수
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // 피벗은 항상 배열의 마지막 요소로 선택합니다.
    int i = (low - 1); // 작은 요소들의 끝 지점

    for (int j = low; j <= high - 1; j++) {
        // 현재 요소가 피벗보다 작으면, 작은 그룹의 끝에 있는 요소와 교환합니다.
        if (arr[j] < pivot) {
            i++; // 작은 그룹의 끝을 증가시킵니다.
            swap(&arr[i], &arr[j]);
        }
    }
    // 피벗을 올바른 위치로 이동시킵니다.
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// 퀵정렬 함수
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // 배열을 분할하고, 피벗의 위치를 가져옵니다.
        int pi = partition(arr, low, high);

        // 피벗을 기준으로 재귀적으로 정렬합니다.
        quickSort(arr, low, pi - 1); // 작은 그룹 정렬
        quickSort(arr, pi + 1, high); // 큰 그룹 정렬
    }
}

// 배열을 출력하는 함수
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// 메인 함수
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("정렬 전 배열: \n");
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printf("정렬 후 배열: \n");
    printArray(arr, n);
    return 0;
}
