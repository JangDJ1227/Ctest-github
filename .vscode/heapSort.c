#include <stdio.h>

// 힙 정렬을 위한 함수들
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

// 배열의 요소를 교환하는 함수
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 힙을 구성하는 함수
void heapify(int arr[], int n, int i) {
    int largest = i; // 부모 노드의 인덱스
    int left = 2 * i + 1; // 왼쪽 자식 노드의 인덱스
    int right = 2 * i + 2; // 오른쪽 자식 노드의 인덱스

    // 왼쪽 자식이 부모보다 크다면 largest 갱신
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 오른쪽 자식이 부모보다 크다면 largest 갱신
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // largest가 부모가 아니라면 교환하고 재귀적으로 힙을 구성
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// 힙 정렬을 수행하는 함수
void heapSort(int arr[], int n) {
    // 최대 힙을 구성
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 힙에서 요소를 하나씩 추출하여 정렬
    for (int i = n - 1; i > 0; i--) {
        // 최대값(루트)을 현재 범위의 맨 뒤로 이동
        swap(&arr[0], &arr[i]);
        // 힙 크기를 줄이고, 변경된 루트에 대해 최대 힙을 구성
        heapify(arr, i, 0);
    }
}

// 배열을 출력하는 함수
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("원본 배열: \n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("정렬된 배열: \n");
    printArray(arr, n);
    return 0;
}
