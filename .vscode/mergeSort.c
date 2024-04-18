#include <stdio.h>
#include <stdlib.h>

// 두 개의 서브 배열을 병합하는 함수
void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // 임시 배열을 생성하고 데이터를 복사
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // 두 개의 임시 배열을 병합하여 정렬된 배열을 생성
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 남은 요소들을 복사
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 병합 정렬 함수
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // 배열을 중간으로 분할
        int middle = left + (right - left) / 2;

        // 두 개의 서브 배열에 대해 재귀적으로 정렬
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // 정렬된 서브 배열을 병합
        merge(arr, left, middle, right);
    }
}

// 배열 출력 함수
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// 주 함수
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("주어진 배열: \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\n정렬된 배열: \n");
    printArray(arr, arr_size);
    return 0;
}
