#include <iostream>
#include <chrono>
#include <pthread.h>

using namespace std;
using namespace std::chrono;

// QUICK SORT THE PARTITION FUNCTION
int partition(int A[], int start_index, int end_index)
{
    int x = A[end_index];
    int i = start_index - 1;

    for (int j = start_index; j <= end_index - 1; j++)
    {
        if (A[j] <= x)
        {
            i++;
            swap(A[i], A[j]);
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
        QUCIKSORT_FUNCTION(A, start_index, q - 1);
        QUCIKSORT_FUNCTION(A, q + 1, end_index);
    }
}

const int ARRAYS_SIZE = 10000000;
int main()
{
    // creating the array and setting the array size according to the need
    int *array = new int[ARRAYS_SIZE];
    srand(time(0));
    // initializing the random vaklues to the array
    for (int i = 0; i < ARRAYS_SIZE; ++i)
    {
        array[i] = rand() % 100;
    }
    // begin of the chrono
    auto Begin = high_resolution_clock::now();
    // calulating the time for the array
    pthread_t thread;
    int args[] = {array, 0, ARRAYS_SIZE - 1};
    pthread_create(&thread, NULL, QUCIKSORT_FUNCTION, (void *)args);
    pthread_join(thread, NULL);
    // track of the time at which end
    auto end = high_resolution_clock::now();
    // duartion is the end - begin and it will tell weathe we  want it in milliseconds or mircoseconds
    auto durations = duration_cast<milliseconds>(end - Begin);
    // printingthe time
    cout << "Quick sort sequential time taken -->" << durations.count() << " MilliSec" << endl;
    return 0;
}