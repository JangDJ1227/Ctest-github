#include <stdio.h>
static int number=1;
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
            printf("%d: ",number);
            number++;
            for(int k=0;k<6;k++){
                printf("%d ",arr[k]);
            }
            printf("\n");
        }
    }
    // 피벗을 올바른 위치로 이동시킵니다.
    swap(&arr[i + 1], &arr[high]);
    printf("%d: ",number);
    number++;
    for(int k=0;k<6;k++){
            printf("%d ",arr[k]);
        }
        printf("\n");
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
// 메인 함수
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("정렬 전 배열: \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    quickSort(arr, 0, n - 1);
    printf("\n정렬 후 배열: \n");
     for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
