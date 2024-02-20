#include <iostream>
using namespace std;
int main() {
    cout << "Hello World!" << endl;
    // MATRIX A B C 
    cout<<"ENTER THE SIZE OF THE ARRAY YOU WANT TO PRINT";
    int random_size;
    cin>>random_size;
    int ARRAY_A[random_size][random_size]; // Assuming the maximum size of the matrix is 100
    int ARRAY_B[random_size][random_size];
    int ARRAY_C[random_size][random_size];

    cout<<"GENERATING THE RANDOM WITH NIRAL DIRECT INSERTION";

    cout<<"---INSERTING THE VALUES IN THE MATRIX A \n";

    for(int i=0;i<random_size;i++)
    {
      for(int j=0;j<random_size;j++)
      {
        ARRAY_A[i][j] = rand();
      }
    }

    cout<<"---INSERTING THE VALUES IN THE MATRIX B \n ";
    for(int i=0;i<random_size;i++)
    {
      for(int j=0;j<random_size;j++)
      {
        ARRAY_B[i][j] = rand();
      }
    }

    cout<<"---PRINTING THE MATRIX A \n  ";

    for(int i = 0; i <random_size; ++i) {
        for(int j = 0; j < random_size; ++j) {
            cout << ARRAY_A[i][j] << " "; 
        }
        cout << endl;
    }

     cout<<"---PRINTING THE MATRIX B \n";
    for(int i = 0; i < random_size; ++i) {
        for(int j = 0; j <random_size; ++j) {
            cout << ARRAY_B[i][j] << " "; 
        }
        cout << endl;
    }
 
     cout<<"-- INSERTING THE VALUES TO THE MATRIX C -- ";

    for(int i=0;i<random_size;i++)
    {
      for(int j=0;j<random_size;j++)
      {
        ARRAY_C[i][j] = ARRAY_A[i][j]*ARRAY_B[i][j];
      }
    }

    cout<<"-- PRINTING THE VALUES TO  THE VALUES TO THE MATRIX C --\n ";
    for(int i = 0; i < random_size; ++i) {
        for(int j = 0; j <random_size; ++j) {
            cout << ARRAY_C[i][j] << " "; 
        }
        cout << endl;
    }
    
    return 0;
}
