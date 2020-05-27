#include <iostream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <algorithm>

#include "..\\commonfunctions.h"
#include "recursion.h"

int main() {
    
    //the chrono std::chrono variables are used to show various execution times
    std::chrono::steady_clock::time_point start1, start2, start3, finish1, finish2, finish3;
    std::chrono::duration<double> timeDiff1, timeDiff2, timeDiff3;

//------------------------------------------------------------------------------
// block for testing/demonstrating basic recursive functions
//------------------------------------------------------------------------------
{
    std::cout << "Enter an integer for tail_recursion(int n) and head_recursion(int n): ";
    int N {};
    N = userIntInput();
    
    tail_recursion(N);  //print N then call N-1, should print N, N-1, N-2, N-3, ..., 0
    std::cout << std::endl;
    head_recursion(N);  //call N-1, then print N, should print 0, 1, 2, ... ,N
    std::cout << std::endl;
    
    std::cout << "Enter an integer for static_var_recursion(int n) demonstration: ";
    N = userIntInput();
    std::cout << static_var_recursion(N) << std::endl;  //example of recursion that uses a static variable in the function
    std::cout << std::endl;
    std::cout << "Calling static_var_recursion a 2nd time from main\n";
    std::cout << static_var_recursion(N) << std::endl;  //example of recursion that uses a static variable in the function
    std::cout << std::endl;
    
    std::cout << "Enter an integer for tree_recursion(int n) demonstration: ";
    N = userIntInput();
    tree_recursion(N);      //in tree recursion, the recursive funtion calls itself multiple times
    std::cout << std::endl;
    
    std::cout << "Enter an integer for indirect_recursion_A(int n) and indirect_recursion_B(int n) demonstration: ";
    N = userIntInput();
    indirect_recursion_A(N); //in indirect recursion, two functions have references to one another
    std::cout << std::endl;
    indirect_recursion_B(N); //call again starting with the other function
    std::cout << std::endl;

    std::cout << "Enter an integer for nested_recursion(int n) demonstration: ";
    N = userIntInput();
    nested_recursion(99); //in nested recurstion, a recursive function parameter is a call to the recursive function
    std::cout << std::endl;
}

//------------------------------------------------------------------------------
// block for testing/demonstrating sum of all natural numbers functions
//------------------------------------------------------------------------------
{
    std::cout << "Enter an integer to find the sum of all natural numbers up to N: ";
    int N{}, sum1{}, sum2{}, sum3{};
    N = userIntInput();
    
    start1 = std::chrono::steady_clock::now();
    sum1 = sum_of_n_recursion(N);
    finish1 = std::chrono::steady_clock::now();
    timeDiff1 = finish1-start1;
    
    start2 = std::chrono::steady_clock::now();
    sum2 = sum_of_n_loop(N);
    finish2 = std::chrono::steady_clock::now();
    timeDiff2 = finish2-start2;
    
    start3 = std::chrono::steady_clock::now();
    sum3 = sum_of_n_formula(N);
    finish3 = std::chrono::steady_clock::now();
    timeDiff3 = finish3-start3;
    
    std::cout << std::setprecision(9) << std::fixed;
    std::cout << "Using recursion to find sum of all natural numbers up to " << N << ": " << sum1;
    std::cout << "\nIt took " << timeDiff1.count() << " seconds with recursion\n" << std::endl;
    
    std::cout << "Using a loop to find sum of all natural numbers up to " << N << ": " << sum2;
    std::cout << "\nIt took " << timeDiff2.count() << " seconds with a loop\n" << std::endl;
    
    std::cout << "Using a formula to find sum of all natural numbers up to " << N << ": " << sum3;
    std::cout << "\nIt took " << timeDiff3.count() << " seconds with a formula\n" << std::endl;
}

//------------------------------------------------------------------------------
// block for testing/demonstrating factorial functions
//------------------------------------------------------------------------------
{
    std::cout << "Enter an integer to find the factorial of N: ";
    int N{};
    unsigned long long facto1{}, facto2{};
    
    N = userIntInput();
    
    start1 = std::chrono::steady_clock::now();
    facto1 = factorial_recursion(N);
    finish1 = std::chrono::steady_clock::now();
    timeDiff1 = finish1-start1;
    
    start2 = std::chrono::steady_clock::now();
    facto2 = factorial_loop(N);
    finish2 = std::chrono::steady_clock::now();
    timeDiff2 = finish2-start2;
    
    
    std::cout << std::setprecision(9) << std::fixed;
    std::cout << "Using recursion to find factorial of " << N << ": " << facto1;
    std::cout << "\nIt took " << timeDiff1.count() << " seconds with recursion\n" << std::endl;
    
    std::cout << "Using a loop to find factorial of " << N << ": " << facto2;
    std::cout << "\nIt took " << timeDiff2.count() << " seconds with a loop\n" << std::endl;
    
}
    
//------------------------------------------------------------------------------
// block for testing/demonstrating power (m^n) functions
//------------------------------------------------------------------------------
{
    
    int m{}, n{};
    unsigned long long power1{}, power2{}, power3{};
    
    std::cout << "Enter number (m) to calculate m^n: ";
    m = userIntInput();
    std::cout << "Enter number (n) to calculate m^n: ";
    n = userIntInput();
    
    start1 = std::chrono::steady_clock::now();
    power1 = m_power_n_recursion(m,n);
    finish1 = std::chrono::steady_clock::now();
    timeDiff1 = finish1-start1;
    
    start2 = std::chrono::steady_clock::now();
    power2 = m_power_n_loop(m,n);
    finish2 = std::chrono::steady_clock::now();
    timeDiff2 = finish2-start2;
    
    start3 = std::chrono::steady_clock::now();
    power3 = m_power_n_cmath(m,n);
    finish3 = std::chrono::steady_clock::now();
    timeDiff3 = finish3-start3;
    
    
    std::cout << std::setprecision(9) << std::fixed;
    std::cout << "Using recursion to find power " << m << "^" << n << ": " << power1;
    std::cout << "\nIt took " << timeDiff1.count() << " seconds with recursion\n" << std::endl;
    
    std::cout << "Using a loop to find power " << m << "^" << n << ": " << power2;
    std::cout << "\nIt took " << timeDiff2.count() << " seconds with a loop\n" << std::endl;
    
    std::cout << "Using std::pow() in <cmath> to find power " << m << "^" << n << ": " << power3;
    std::cout << "\nIt took " << timeDiff2.count() << " seconds with std::pow()\n" << std::endl;
}
    
//------------------------------------------------------------------------------
// block for testing/demonstrating Taylor Series (e^x) = 1 + x/1 + x*2/2! ...
//------------------------------------------------------------------------------
{
    int x{}, p{};
    
    std::cout << "Enter number (x) to calculate e^x with Taylor Series: ";
    x = userIntInput();
    std::cout << "Enter number p to tell how many terms to use in the series: ";
    p = userIntInput();
    
    double taylor1{}, taylor2{};
    
    start1 = std::chrono::steady_clock::now();
    taylor1 = taylor_recursion(x,p);
    finish1 = std::chrono::steady_clock::now();
    timeDiff1 = finish1-start1;
    
    start2 = std::chrono::steady_clock::now();
    taylor2 = taylor_loop(x,p);
    finish2 = std::chrono::steady_clock::now();
    timeDiff2 = finish2-start2;

    std::cout << std::setprecision(9) << std::fixed;
    std::cout << "Using recursion to find e^x with Taylor series e^" << x << ": " << taylor1;
    std::cout << "\nIt took " << timeDiff1.count() << " seconds with recursion\n" << std::endl;
    
    std::cout << "Using loops to find e^x with Taylor series e^" << x << ": " << taylor2;
    std::cout << "\nIt took " << timeDiff2.count() << " seconds with a loop\n" << std::endl;
}

//------------------------------------------------------------------------------
// block for testing/demonstrating fibonacci series functions
//------------------------------------------------------------------------------
{
    std::cout << "Enter an integer to find the nth number of the fibonacci series: ";
    int n{}, fibo1{}, fibo2{}, fibo3{};
    int lookup[100] {0};
    std::fill_n(lookup,100,-1); //std::fill_n is defind in <algorithm>
    
    n = userIntInput();
    
    start1 = std::chrono::steady_clock::now();
    fibo1 = fibonacci_recursion(n);
    finish1 = std::chrono::steady_clock::now();
    timeDiff1 = finish1-start1;
    
    start2 = std::chrono::steady_clock::now();
    fibo2 = fibonacci_memoization(n,lookup);
    finish2 = std::chrono::steady_clock::now();
    timeDiff2 = finish2-start2;
    
    start3 = std::chrono::steady_clock::now();
    fibo3 = fibonacci_loop(n);
    finish3 = std::chrono::steady_clock::now();
    timeDiff3 = finish3-start3;
    
    std::cout << std::setprecision(9) << std::fixed;
    std::cout << "Using recursion to find the nth number of the fibonacci series " << n << ": " << fibo1;
    std::cout << "\nIt took " << timeDiff1.count() << " seconds with recursion\n" << std::endl;
    
    std::cout << "Using memoization to find the nth number of the fibonacci series " << n << ": " << fibo2;
    std::cout << "\nIt took " << timeDiff2.count() << " seconds with memoization\n" << std::endl;
    
    std::cout << "Using iteration to find the nth number of the fibonacci series " << n << ": " << fibo3;
    std::cout << "\nIt took " << timeDiff3.count() << " seconds with iteration\n" << std::endl;
}
    
//------------------------------------------------------------------------------
// block for testing/demonstrating nCr combination (permutations) formula
//------------------------------------------------------------------------------
{
    int n{}, r{};
    
    std::cout << "Enter number (n) to calculate nCr combination formula: ";
    n = userIntInput();
    std::cout << "Enter number (r) to calculate nCr combination formula: ";
    r = userIntInput();
    
    int ncr1{}, ncr2{};
    
    start1 = std::chrono::steady_clock::now();
    ncr1 =nCr_recursion(n,r);
    finish1 = std::chrono::steady_clock::now();
    timeDiff1 = finish1-start1;
    
    start2 = std::chrono::steady_clock::now();
    ncr2 = nCr_recursion(n,r);
    finish2 = std::chrono::steady_clock::now();
    timeDiff2 = finish2-start2;

    std::cout << std::setprecision(9) << std::fixed;
    std::cout << "\nUsing recursion to find nCr with " << n << "," << r << ": " << ncr1;
    std::cout << "\nIt took " << timeDiff1.count() << " seconds with recursion\n" << std::endl;
    
    std::cout << "Using factorial calcs to find nCr with " << n << "," << r << ": " << ncr2;
    std::cout << "\nIt took " << timeDiff2.count() << " seconds with factorials\n" << std::endl;
}

//------------------------------------------------------------------------------
// block for testing/demonstrating tower of hanoi
//------------------------------------------------------------------------------
{
    std::cout << "Enter number (n) of discs on the Tower of Hanoi: ";
    int n{0};
    n = userIntInput();
    
    tower_of_hanoi(n,'A','B','C');
    std::cout << std::endl;
}
    return 0;
}

