#include <iostream>
using namespace std;
#include <chrono>
int main()
{
    cout << "Hello World!" << endl;
    // MATRIX A B C
    cout << "ENTER THE SIZE OF THE ARRAY YOU WANT TO PRINT";
    int random_size;
    cin >> random_size;
    int ARRAY_A[random_size][random_size]; // Assuming the maximum size of the matrix is 100
    int ARRAY_B[random_size][random_size];
    int ARRAY_C[random_size][random_size];

    cout << "GENERATING THE RANDOM WITH NIRAL DIRECT INSERTION";

    cout << "---INSERTING THE VALUES IN THE MATRIX A \n";
    srand(time(0));
    auto BEGIN_TIMER = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < random_size; i++)
    {
        for (int j = 0; j < random_size; j++)
        {
            ARRAY_A[i][j] = rand();
        }
    }

    cout << "---INSERTING THE VALUES IN THE MATRIX B \n ";
    for (int i = 0; i < random_size; i++)
    {
        for (int j = 0; j < random_size; j++)
        {
            ARRAY_B[i][j] = rand();
        }
    }

    cout << "-- INSERTING THE VALUES TO THE MATRIX C -- ";

    for (int i = 0; i < random_size; i++)
    {
        for (int j = 0; j < random_size; j++)
        {
            ARRAY_C[i][j] = ARRAY_A[i][j] * ARRAY_B[i][j];
        }
    }
    // Stop timer
    auto STOP_TIMER = std::chrono::high_resolution_clock::now();
    // Calculate duration of multiplication
    auto DURATIONS = std::chrono::duration_cast<std::chrono::microseconds>(STOP_TIMER - BEGIN_TIMER);

    cout << "TIME TAKEN FOR MULTIPLICATION IS " << DURATIONS.count() << " MICROSECONDS" << endl;

    return 0;
}
