#include <iostream>
#include <chrono>
#include <omp.h>
using namespace std;
using namespace std::chrono;

// QUICK SORT THE PARTITION FUNCTION
int partition(int A[], int start_index, int end_index)
{
    int x = A[end_index];
    
    int i = start_index - 1;

    #pragma omp parallel for
    for (int j = start_index; j <= end_index - 1; j++)
    {
        if (A[j] <= x)
        {
            #pragma omp critical
            {
                i++;
                swap(A[i], A[j]);
            }
        }
    }
    swap(A[i + 1], A[end_index]);
    return (i + 1);
}

// QUICK SORT RECURSIVE CALLING
void QUCIKSORT_FUNCTION(int A[], int start_index, int end_index)
{
    if (start_index < end_index)
    {
        int q = partition(A, start_index, end_index);
        
        #pragma omp task
        QUCIKSORT_FUNCTION(A, start_index, q - 1);
        
        #pragma omp task
        QUCIKSORT_FUNCTION(A, q + 1, end_index);
    }
}

const int ARRAYS_SIZE = 1000000;

int main()
{
    // creating the array and setting the array size according to the need
    int* array = new int[ARRAYS_SIZE];
    //int array[ARRAYS_SIZE];
    srand(time(0));
    // initializing the random values to the array
    for (int i = 0; i < ARRAYS_SIZE; ++i)
    {
        array[i] = rand() % 1000;
    }
    // begin of the chrono
    auto Begin = high_resolution_clock::now();
    
    // parallel region for sorting
    #pragma omp parallel
    {
        #pragma omp single
        QUCIKSORT_FUNCTION(array, 0, ARRAYS_SIZE - 1);
    }

    // track of the time at which end
    auto end = high_resolution_clock::now();
    // duration is the end - begin and it will tell whether we want it in milliseconds or microseconds
    auto durations = duration_cast<milliseconds>(end - Begin);
    // printing the time
    cout << "Quick sort parallel time taken -->" << durations.count() << " MilliSec" << endl;

    delete[] array; // Don't forget to free the allocated memory
    return 0;
}
