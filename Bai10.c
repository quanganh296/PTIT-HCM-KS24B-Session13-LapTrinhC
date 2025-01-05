#include <stdio.h>
#include <stdlib.h>

void inputArray(int arr[], int *n) {
    printf("Nhap so phan tu can nhap: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhap phan tu arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int n) {
    printf("Gia tri cac phan tu trong mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[], int *n) {
    int pos, val;
    printf("Nhap vi tri can them (0 den %d): ", *n);
    scanf("%d", &pos);
    if (pos < 0 || pos > *n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    printf("Nhap gia tri can them: ");
    scanf("%d", &val);
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    (*n)++;
}

void updateElement(int arr[], int n) {
    int pos, val;
    printf("Nhap vi tri phan tu can sua (0 den %d): ", n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    printf("Nhap gia tri moi cho arr[%d]: ", pos);
    scanf("%d", &val);
    arr[pos] = val;
}

void deleteElement(int arr[], int *n) {
    int pos;
    printf("Nhap vi tri phan tu can xoa (0 den %d): ", *n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= *n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void sortArray(int arr[], int n, int order) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((order == 1 && arr[i] > arr[j]) || (order == 0 && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printArray(arr, n);
}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[100], n = 0;
    int choice, subChoice, key;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("7. Tim kiem phan tu\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                inputArray(arr, &n);
                break;
            case 2:
                printArray(arr, n);
                break;
            case 3:
                insertElement(arr, &n);
                break;
            case 4:
                updateElement(arr, n);
                break;
            case 5:
                deleteElement(arr, &n);
                break;
            case 6:
                printf("MENU CON - Sap xep\n");
                printf("a. Giam dan\n");
                printf("b. Tang dan\n");
                printf("Nhap lua chon sap xep (a/b): ");
                scanf(" %c", &subChoice);
                if (subChoice == 'a') {
                    sortArray(arr, n, 0);
                } else if (subChoice == 'b') {
                    sortArray(arr, n, 1);
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            case 7:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &key);
                printf("MENU CON - Tim kiem\n");
                printf("a. Tim kiem tuyen tinh\n");
                printf("b. Tim kiem nhi phan\n");
                printf("Nhap lua chon tim kiem (a/b): ");
                scanf(" %c", &subChoice);
                if (subChoice == 'a') {
                    int index = linearSearch(arr, n, key);
                    if (index != -1) {
                        printf("Phan tu %d tim thay o vi tri %d.\n", key, index);
                    } else {
                        printf("Phan tu %d khong tim thay.\n", key);
                    }
                } else if (subChoice == 'b') {
                    int index = binarySearch(arr, n, key);
                    if (index != -1) {
                        printf("Phan tu %d tim thay o vi tri %d.\n", key, index);
                    } else {
                        printf("Phan tu %d khong tim thay.\n", key);
                    }
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 8);

    return 0;
}