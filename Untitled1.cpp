#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int currentLength = 0;
    int choice;
    
    do {
        printf("MENU\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Tim gia tri nho nhat va lon nhat trong mang\n");
        printf("4. In ra tong cua tat ca cac phan tu\n");
        printf("5. Them mot phan tu vao cuoi mang\n");
        printf("6. Xoa phan tu tai mot vi tri cu the\n");
        printf("7. Sap xep mang theo thu tu giam dan (Bubble sort)\n");
        printf("8. Tim kiem mot phan tu (Linear search)\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so phan tu: ");
                int n;
                scanf("%d", &n);
                if (n > 0 && n <= MAX_SIZE) {
                    currentLength = n;
                    printf("Nhap cac phan tu: ");
                    for (int i = 0; i < n; ++i) {
                        scanf("%d", &arr[i]);
                    }
                } else {
                    printf("So luong phan tu khong hop le!\n");
                }
                break;
            case 2:
                for (int i = 0; i < currentLength; ++i) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;
            case 3:
                if (currentLength > 0) {
                    int min = arr[0], max = arr[0];
                    for (int i = 1; i < currentLength; ++i) {
                        if (arr[i] < min) min = arr[i];
                        if (arr[i] > max) max = arr[i];
                    }
                    printf("Gia tri nho nhat: %d\n", min);
                    printf("Gia tri lon nhat: %d\n", max);
                } else {
                    printf("Mang rong!\n");
                }
                break;
            case 4:
                if (currentLength > 0) {
                    int tong = 0;
                    for (int i = 0; i < currentLength; ++i) {
                        tong += arr[i];
                    }
                    printf("Tong cac phan tu: %d\n", tong);
                } else {
                    printf("Mang rong!\n");
                }
                break;
            case 5:
                if (currentLength < MAX_SIZE) {
                    int newValue;
                    printf("Nhap gia tri muon them: ");
                    scanf("%d", &newValue);
                    arr[currentLength] = newValue;
                    currentLength++;
                } else {
                    printf("Mang da day!\n");
                }
                break;
            case 6:
                printf("Nhap vi tri muon xoa: ");
                int deleteIndex;
                scanf("%d", &deleteIndex);
                if (deleteIndex >= 0 && deleteIndex < currentLength) {
                    for (int i = deleteIndex; i < currentLength - 1; ++i) {
                        arr[i] = arr[i + 1];
                    }
                    currentLength--;
                } else {
                    printf("Vi tri khong hop le!\n");
                }
                break;
            case 7:
                for (int i = 0; i < currentLength - 1; ++i) {
                    for (int j = 0; j < currentLength - 1 - i; ++j) {
                        if (arr[j] < arr[j + 1]) {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                for (int i = 0; i < currentLength; ++i) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;
            case 8:
                printf("Nhap gia tri muon tim: ");
                int searchValue;
                scanf("%d", &searchValue);
                bool found = false;
                for (int i = 0; i < currentLength; ++i) {
                    if (arr[i] == searchValue) {
                        printf("Gia tri %d ton tai tai vi tri %d\n", searchValue, i);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    printf("Gia tri %d khong ton tai trong mang\n", searchValue);
                }
                break;
        }
    } while (choice != 9);
    return 0;
}

