#include <stdio.h>
#include <stdlib.h>

// Функція для введення елементів масиву
void inputArray(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Введіть елемент #%d: ", i + 1);
        scanf("%lf", &arr[i]);
    }
}

// Функція для виведення елементів масиву
void printArray(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%lf ", arr[i]);
    }
    printf("\n");
}

// Функція для обчислення показника, в якому на k-тому місці стоїть менший елемент
int getIndexOfSmallerElement(double arr[], int n, int k) {
    double *tempArr = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        tempArr[i] = arr[i];
    }
    
    // Використовуємо сортування вставками для сортування масиву
    for (int i = 1; i < n; i++) {
        double key = tempArr[i];
        int j = i - 1;
        while (j >= 0 && tempArr[j] > key) {
            tempArr[j + 1] = tempArr[j];
            j--;
        }
        tempArr[j + 1] = key;
    }
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == tempArr[k - 1]) {
            free(tempArr);
            return i;
        }
    }
    
    // Якщо показник не знайдено, повертаємо -1
    free(tempArr);
    return -1;
}

int main() {
    int n, k;
    printf("Введіть розмір масивів: ");
    scanf("%d", &n);
    
    double *a = malloc(n * sizeof(double));
    double *b = malloc(n * sizeof(double));
    
    printf("Введіть елементи масиву a:\n");
    inputArray(a, n);
    
    printf("Введіть елементи масиву b:\n");
    inputArray(b, n);
    
    printf("Масив a після сортування: ");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                double temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printArray(a, n);
    
    printf("Масив b після сортування: ");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (b[i] > b[j]) {
                double temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    printArray(b, n);
    
    printf("Введіть значення k: ");
    scanf("%d", &k);
    
    int indexA = getIndexOfSmallerElement(a, n, k);
    int indexB = getIndexOfSmallerElement(b, n, k);
    
    if (indexA != -1) {
        printf("У відсортованому масиві a менший елемент на %d-му місці знаходиться на позиції %d\n", k, indexA + 1);
    } else {
        printf("Показник для масиву a не знайдено\n");
    }
    
    if (indexB != -1) {
        printf("У відсортованому масиві b менший елемент на %d-му місці знаходиться на позиції %d\n", k, indexB + 1);
    } else {
        printf("Показник для масиву b не знайдено\n");
    }
    
    free(a);
    free(b);
    
    return 0;
}
