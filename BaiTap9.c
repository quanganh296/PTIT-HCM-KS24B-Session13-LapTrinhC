#include <stdio.h>

int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}
void main_diagonal_and_secondary_diagonal(int arr[100][100],int n,int m ){
   printf("Duong cheo chinh: ");
    for(int i=0;i<n&&i<m;i++)
    { printf("%d ", arr[i][i]);

}
printf("\n");
printf("Duong cheo phu: ");
 for(int i=0;i<n&&i<m;i++){
        printf("%d ", arr[i][m-i-1]);
        }
        printf("\n");
    }
   void border(int arr[100][100], int n, int m) {
   
    for (int j = 0; j < m; j++) {
        printf("%d ", arr[0][j]);
    }
    printf("\n");

    for (int i = 1; i < n - 1; i++) {
        printf("%d ", arr[i][0]); 
        for (int j = 1; j < m - 1; j++) {
            printf("  ");
        }
        if (m > 1) {
            printf("%d", arr[i][m - 1]);   
        }
        printf("\n");
    }

    if (n > 1) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[n - 1][j]);
        }
        printf("\n");
    }
}
   



int main() {
    int n, m;
    printf("Nhập số hàng: ");
    scanf("%d", &n);
    printf("Nhập số cột: ");
    scanf("%d", &m);

    int arr[n][m];

    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhập giá trị các phần tử của mảng\n");
        printf("2. In giá trị các phần tử của mảng theo ma trận\n");
        printf("3. In ra các phần tử ở góc theo ma trận\n");
        printf("4. In ra các phần tử nằm trên đường biên theo ma trận\n");
        printf("5. In ra các phần tử nằm trên đường chéo chính và chéo phụ theo ma trận\n");
        printf("6. In ra các phần tử là số nguyên tố theo ma trận\n");
        printf("7. Thoát\n");
        printf("Nhập lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
               printf("Nhap cac phan tu cua mang:\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                     printf("phan tu thu %d cua hang thu %d cot thu %d: ", j+1,i+1,j+1);
                    scanf("%d",&arr[i][j]);
                       
                    
                }
                printf("\n");
            }
                break;
            case 2:
                 printf("Mang vua nhap theo ma tran: \n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    printf("%d ",arr[i][j]);
                       
                    
                }
                printf("\n");
            }
                break;
            case 3:
          if (n > 0 && m > 0) {
        printf("Goc tren ben trai: %d\n", arr[0][0]);
        if (m > 1) {
            printf("Goc tren ben phai: %d\n", arr[0][m-1]);
        }
        if (n > 1) {
            printf("Goc duoi ben trai: %d\n", arr[n-1][0]);
        }
        if (n > 1 && m > 1) {
            printf("Goc duoi ben phai: %d\n", arr[n-1][m-1]);
        }
    } else {
        printf("Ma tran ko co goc\n");
    }

                break;
            case 4:
                   border(arr,n,m);
                break;
            case 5:
                 if (n <= 0 || m <= 0 || n > 100 || m > 100||n!=m) {
                    printf("Ma tra nay ko co duong cheo");
                    return 1;
                }
                else{
                    main_diagonal_and_secondary_diagonal(arr,n,m);

                }
                break;
            case 6:
            printf("Các phần tử là số nguyên tố:\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (is_prime(arr[i][j])) {
                        printf("%d ", arr[i][j]);
                    }
                }
                printf("\n");
            }
            break;
            case 7:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
        }
    } while (choice != 7);

    return 0;
}
