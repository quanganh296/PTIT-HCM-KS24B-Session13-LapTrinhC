#include <stdio.h>

int main() {
    int rows, cols;

 
    printf("Nhập số hàng của ma trận: ");
    scanf("%d", &rows);
    printf("Nhập số cột của ma trận: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nhập giá trị tại hàng %d, cột %d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Ma trận vừa tạo là:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
