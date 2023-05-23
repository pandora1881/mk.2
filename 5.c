#include <stdio.h>
#include <math.h>

// Функція для обчислення показника √(x + y)
double calculateIndex(double x, double y) {
    return sqrt(x + y);
}

// Функція для введення елементів масиву
void inputArray(double arr[], int n) {
    printf("Введіть елементи масиву:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d]: ", i);
        scanf("%lf", &arr[i]);
    }
}

// Функція для виведення елементів масиву
void printArray(double arr[], int n) {
    printf("Елементи масиву:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d]: %.2lf\n", i, arr[i]);
    }
}

// Функція для обчислення значення l
double calculateL(double arr[], int n) {
    double result = 0.0;
    for (int i = n - 1; i >= 0; i--) {
        result = calculateIndex(arr[i], result);
    }
    return result;
}

int main() {
    int n;
    printf("Введіть натуральне число n: ");
    scanf("%d", &n);
    
    double arr[n];
    inputArray(arr, n);
    
    printArray(arr, n);
    
    double l = calculateL(arr, n);
    printf("Значення l: %.2lf\n", l);
    
    return 0;
}
