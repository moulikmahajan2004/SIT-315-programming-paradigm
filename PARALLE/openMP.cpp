#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <omp.h>
using namespace std;


//MATRIX SIZE INTIALISED
const int MATRIX_SIZE = 300;

// declaring the array with size
int ARRAY_A[MATRIX_SIZE][MATRIX_SIZE];
int ARRAY_B[MATRIX_SIZE][MATRIX_SIZE];
int ARRAY_C[MATRIX_SIZE][MATRIX_SIZE];

//intializing the matrix with random values
void RANDOM_VALUES_TO_MATRIXS(int ENTER_MATRICS[][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            ENTER_MATRICS[i][j] = rand() % 100;
        }
    }
}

int main()
{
    srand(time(0));
    //intializing the matrixs 
    RANDOM_VALUES_TO_MATRIXS(ARRAY_A);
    RANDOM_VALUES_TO_MATRIXS(ARRAY_B);
     //begin timer to count the execution process 
    auto BEGIN_TIMER = std::chrono::high_resolution_clock::now();
    #pragma omp parallel for
    for(int i=0; i<MATRIX_SIZE; i++)
    {
        for(int j = 0; j < MATRIX_SIZE; j++)
        {
            ARRAY_C[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; k++)
            {
                ARRAY_C[i][j] += ARRAY_B[i][k] * ARRAY_A[k][j];
            }
        }
    }
    //closing the timer 
    auto CLOSE_TIMER = std::chrono::high_resolution_clock::now();
    //total duration
    auto TOTAL_DURATION = std::chrono::duration_cast<std::chrono::microseconds>(CLOSE_TIMER - BEGIN_TIMER);
    //printing the execution time 
    cout << "TOTAL EXECUTION TIME STATUS: " << TOTAL_DURATION.count() << " MICROSECONDS";
    return 0;
}
