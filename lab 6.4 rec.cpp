#include <iostream>
#include <cmath>
using namespace std;

// Функція для введення елементів масиву
void inputArray(double* arr, int n) {
    cout << "Enter " << n << " elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

// Функція для виведення масиву
void printArray(const double* arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функція для підрахунку кількості елементів у діапазоні [A, B]
int countInRange(const double* arr, int n, double A, double B) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] >= A && arr[i] <= B) {
            ++count;
        }
    }
    return count;
}

// Функція для обчислення суми елементів після максимального
double sumAfterMax(const double* arr, int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }

    double sum = 0;
    for (int i = maxIndex + 1; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}

// Функція для сортування парних елементів за спаданням модулів
void sortEvenByAbs(double* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (static_cast<int>(arr[i]) % 2 == 0) {
            for (int j = i + 1; j < n; ++j) {
                if (static_cast<int>(arr[j]) % 2 == 0 && fabs(arr[i]) < fabs(arr[j])) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
}

int main() {
    int n;
    double A, B;
    cout << "Enter the number of elements (n): ";
    cin >> n;
    cout << "Enter A and B for the range [A, B]: ";
    cin >> A >> B;

    double* arr = new double[n];
    inputArray(arr, n);

    cout << "Original array: ";
    printArray(arr, n);

    int count = countInRange(arr, n, A, B);
    cout << "Number of elements in the range [" << A << ", " << B << "]: " << count << endl;

    double sum = sumAfterMax(arr, n);
    cout << "Sum of elements after the maximum element: " << sum << endl;

    sortEvenByAbs(arr, n);
    cout << "Modified array after sorting even elements by descending absolute values: ";
    printArray(arr, n);

    delete[] arr;
    return 0;
}
