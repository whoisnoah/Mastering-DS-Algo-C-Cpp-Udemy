#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <algorithm>

#include "..\\commonfunctions.h"
#include "arrays.h"

int main() {
    
    //the chrono std::chrono variables are used to show various execution times
    std::chrono::steady_clock::time_point start1, start2, start3, finish1, finish2, finish3;
    std::chrono::duration<double> timeDiff1, timeDiff2, timeDiff3;

//------------------------------------------------------------------------------
// basic array declaration and initialization
//------------------------------------------------------------------------------
{
    int    iArray[] {0,1,2,3,4,5};
    char   cArray[] {'a','b','c','d'};
    double dArray[3] {1.0,1.1,1.2};
    
    std::cout << "iArray contains: ";
    cout_array(iArray, sizeof(iArray)/sizeof(iArray[0]));
    std::cout << "cArray contains: ";
    cout_array(cArray, sizeof(cArray)/sizeof(cArray[0]));
    std::cout << "dArray contains: ";
    cout_array(dArray, sizeof(dArray)/sizeof(dArray[0]));
    
    int s {};
    std::cout << "Enter the size of the arry to create: ";
    s = userIntInput();
    int runtimeArray[s];
    int n{};
    std::cout << "Enter an initial value to fill the array with: ";
    n = userIntInput();
    std::fill_n(runtimeArray,s,n); //std::fill_n is defind in <algorithm>
    std::cout << std::endl;
    
    std::cout << "runtimeArray contains: ";
    cout_array(runtimeArray, sizeof(runtimeArray)/sizeof(runtimeArray[0]));
}  
    
//------------------------------------------------------------------------------
// static vs dynamic arrays / adding elements to a dynamic array
//------------------------------------------------------------------------------
{
    //declare and init a regular array, and a int* with allocated memory for 5 ints
    int iArr[5] {2,4,5,6,10};
    int* iArrPtr = new int[5];
    
    //pointers to arrays can be addressed with pointer arithmetic or like a regular array
    iArrPtr[0] = 1;
    *(iArrPtr+1) = 3;
    iArrPtr[2] = 5;
    *(iArrPtr+3) = 7;
    iArrPtr[4] = 9;
    
    int len {5}; //length of of iArrPtr
    
    //display the arrays and their memory locations
    std::cout << std::setw(36) << std::left << "iArr is ";
    cout_array(iArr, sizeof(iArr)/sizeof(iArr[0]));
    std::cout << std::setw(36) << std::left << "The addresses for iArr are ";
    cout_addrArray(iArr, sizeof(iArr)/sizeof(iArr[0]));
    
    std::cout << std::setw(36) << std::left << "iArrPtr is ";
    //there's no way to find the length of an array so we must know the size
    //if we need to iteratate through the array in the function
    //sizeof(iArrPtr) will return the size of the pointer, not the array
    cout_array(iArrPtr, len);
    std::cout << std::setw(36) << std::left << "The addresses for iArrPtr are ";
    cout_addrArray(iArrPtr, len);
    
    //add element to the end of the array
    iArrPtr = add_element(iArrPtr,len,11);
    std::cout << std::setw(36) << std::left << "new iArrPtr is ";
    cout_array(iArrPtr, len);
    std::cout << std::setw(36) << std::left << "The new addresses for iArrPtr are ";
    cout_addrArray(iArrPtr, len);
    
    delete[] iArrPtr;
    std::cout << std::endl;
}
    
//------------------------------------------------------------------------------
// block for testing/demonstrating simple 2D arrays
//------------------------------------------------------------------------------
{
    //simple 2D static array declaration, assignment, and print
    int A[3][4]={{1,2,3,4},{2,4,6,8},{1,3,5,7}};
    for(int i {0}; i < 3; ++i){
        std::cout << "[ ";
        for(int j {0}; j < 4; ++j){
            std::cout << A[i][j] << " ";
        }
        std::cout << "]\n";
    }
    std::cout << std::endl;
    
    //array declaration for 2D array with array of pointers
    //this is really more like a static array of pointers than a dynamic 2D array
    int* B[3];
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];
    for(int i {0}; i < 3; ++i){
        std::cout << "[ ";
        for(int j {0}; j < 4; ++j){
            B[i][j] = i + j;
            std::cout << B[i][j] << " ";
        }
        std::cout << "]\n";
    }
    std::cout << std::endl;
    delete [] B[0];
    delete [] B[1];
    delete [] B[2];
    
    //array declaration for 2D array with pointer pointer
    //this is a truly dynamic 2D array
    int rows,columns {};
    std::cout << "Enter the number of rows in the 2D array: ";
    rows = userIntInput();
    std::cout << "Enter the number of rows in the 2D array: ";
    columns = userIntInput();
    
    int** C = new int*[rows];

    for(int i {0}; i < rows; ++i){
        C[i] = new int[columns];
        std::cout << "[ ";   
        for(int j {0}; j < columns; ++j){
            C[i][j] = i + j + 6;
            std::cout << std::setw(2) << std::left << C[i][j] << " ";
        }
        std::cout << "]\n";
    }
    
    //since the full array is dynamic, we need to delete each row pointer before
    //we delete the pointer pointer
    for(int i {0}; i < rows; ++i)
        delete[] C[i];
    delete [] C;
}
    
    
    
    return 0;

}
