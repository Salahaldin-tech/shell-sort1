#include <iostream>
#include <chrono>

using namespace std;

// Shell Sort implementation
void shellSort(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i += 1) {
            int temp = arr[i];
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}


void test_execution_time(int n, int iterations = 10) {
    // Create an array with n elements
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = n - i; 
    }

    auto start_time = chrono::high_resolution_clock::now(); // Start time
    for (int i = 0; i < iterations; ++i) {
        shellSort(arr, n); 
    }
    auto end_time = chrono::high_resolution_clock::now(); // End time

    // Calculate average execution time in microseconds
    chrono::duration<double, micro> total_time_us = end_time - start_time;
    double average_time_us = total_time_us.count() / iterations;
    cout << "Shell Sort on array with size " << n
         << ", Average Execution Time: " << average_time_us << " microseconds" << endl;

    delete[] arr; 
}

int main() {
    // Testing with different values of n
    int sizes[] = {100, 1000, 10000, 100000, 1000000};
    for (int n : sizes) {
        test_execution_time(n);
    }
    return 0;
}
