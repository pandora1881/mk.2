#include <stdio.h>

// Функція для введення елементів масиву
void inputArray(float array[], int n) {
    printf("Введіть елементи масиву:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &array[i]);
    }
}

// Функція для виведення елементів масиву
void printArray(float array[], int n) {
    printf("Елементи масиву:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

// Функція для сортування масиву
void sortArray(float array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                float temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Функція для знаходження позиції меншого елемента після сортування
int findPosition(float sortedArray[], float originalArray[], int n, float element) {
    for (int i = 0; i < n; i++) {
        if (sortedArray[i] == element) {
            for (int j = 0; j < n; j++) {
                if (originalArray[j] == element) {
                    return j;
                }
            }
        }
    }
    return -1;  // Повертає -1, якщо елемент не знайдено
}

int main() {
    int n, k;
    printf("Введіть розмір масиву: ");
    scanf("%d", &n);

    float a[100], b[100];

    inputArray(a, n);
    inputArray(b, n);

    sortArray(a, n);
    sortArray(b, n);

    printf("Відсортовані масиви:\n");
    printArray(a, n);
    printArray(b, n);

    printf("Введіть значення k: ");
    scanf("%d", &k);

    float element = (a[k - 1] < b[k - 1]) ? a[k - 1] : b[k - 1];
    int position = findPosition(a, b, n, element);
    if (position != -1) {
        printf("Після сортування на %d-му місці стоїть менший елемент %.2f\n", k, element);
        printf("Оригінальна позиція меншого елемента: %d\n", position);
    } else {
        printf("Елемент %.2f не знайдено.\n", element);
    }

    return 0;
}
