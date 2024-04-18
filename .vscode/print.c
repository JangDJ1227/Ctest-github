#include <stdio.h>
int mat(int arr[][]);

int main(void){
    int bi[8][4];
    printf("7C3을 구하기\n");
    int result = mat(bi);

    for(int i=0;i<7;i++){
        for(int j=0;j<4;j++){
            printf("%d ",bi[i][j]);
        }
        printf("\n");
    }
    printf("result: %d\n",bi[7][3]);

    return 0;
}

int mat(int arr[][]){
    int i=8;
    int j=4;

    for(int x=0;x<i;i++){
        for(int y=0;y<x;y++){
            if(y=0||x==y)
                C[x][y]=1;
            else
                arr[i][j]=arr[i-1][j]+arr[i-1][j];
        }
    }
}