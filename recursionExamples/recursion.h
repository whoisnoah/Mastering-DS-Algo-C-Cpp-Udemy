#ifndef _RECURSION_HPP_
#define _RECURSION_HPP_

//------------------------------------------------------------------------------
// tail recursion means the recursive call is AFTER all other operations
//------------------------------------------------------------------------------
void tail_recursion(int n){
    std::cout << "Just entered tail_recursion(): " << n << "\n";
    if (n > 0){
        tail_recursion(n-1);
    } else
        std::cout << "n is not > 0, tail_recursion will NOT be called again\n";
}

//------------------------------------------------------------------------------
// head recursion means the recursive call is BEFORE all other operations
//------------------------------------------------------------------------------
void head_recursion(int n){
    if (n > 0){
        head_recursion(n-1);
    } else
        std::cout << "n is not > 0, head_recursion will NOT be called again\n";
    
    std::cout << "Now leaving head_recursion(): " << n << "\n";
}

//------------------------------------------------------------------------------
// example of a static variable in a recursive function... why???
// don't do this it's bad practice
//------------------------------------------------------------------------------
int static_var_recursion(int n){
    static int x {0};
    std::cout << "Entering static_var_recursion(" << n << ") - ";
    if (n > 0){
        ++x;
        std::cout << "x == " << x << "\n";
        return static_var_recursion(n-1) + x;
    }
    else {
        std::cout << "final sum == ";
        return 0;
    }
}

//------------------------------------------------------------------------------
// tree recursion is when one recursive function calls itself multiple times
//------------------------------------------------------------------------------
void tree_recursion(int n){
    std::cout << "Entering tree_recursion(" << n << ")\n";
    if (n > 0){
        std::cout << "1st recursive call - ";
        tree_recursion(n - 1);
        std::cout << "2nd recursive call - ";
        tree_recursion(n - 1);
    }
}

//------------------------------------------------------------------------------
// indirect recursion is when two or more functions call each other
//------------------------------------------------------------------------------
void indirect_recursion_B(int n);
void indirect_recursion_A(int n){
    
    if (n > 0){
        std::cout << "In indirect_recursion_A(" << n << ") - calling indirect_recursion_B(" << n-1 << ")\n";
        indirect_recursion_B(n-1);
    }
}
void indirect_recursion_B(int n){
    
    if (n > 1){
        std::cout << "In indirect_recursion_B(" << n << ") - calling indirect_recursion_A(" << n/2 << ")\n";
        indirect_recursion_A(n/2);
    }
}

//------------------------------------------------------------------------------
// nested recursion is when a recursive function parameter is a call to the 
// recursive function
//------------------------------------------------------------------------------
int nested_recursion(int n){
    std::cout << "In nested_recursion(" << n << ") - ";
    if (n > 100){
        std::cout << "return n-10 == " << n-10 << "\n";
        return n-10;
    }
    else{
        std::cout << "calling nested_recursion(" << n+11 << ")\n";
        return nested_recursion(nested_recursion(n+11));
    }
}

//------------------------------------------------------------------------------
// functions to calculate the sum of the first 'n' natural numbers
// recursive definition: 1 + 2 + 3 + 4 + ... + n
// sum of (n) = 1 + 2 + 3 + ... + (n-1) + n
// alternative function for sum of n = (n*(n+1)) / 2
//------------------------------------------------------------------------------
int sum_of_n_recursion(int n){
    
    if (n > 0)
        return n + sum_of_n_recursion(n-1);
    else
        return 0;
}
int sum_of_n_loop(int n){
    
    int sum {};
    for (int i{0}; i <= n; ++i)
        sum += i;
    
    return sum;    
}
int sum_of_n_formula(int n){
    
    return (n*(n+1))/2;
}

//------------------------------------------------------------------------------
// functions to calculate the factorial n!
// recursive definition: 1*2*3*4* ... *n
// factorial of n = 1*2*3* ... (n-1)*n
//------------------------------------------------------------------------------
unsigned long long factorial_recursion(int n){
    
    if (n > 0)
        return factorial_recursion(n-1)*n;
    else
        return 1;
}
unsigned long long factorial_loop(int n){
    
    unsigned long long facto {1};
    for (int i{0}; i <= n; ++i)
        facto = (i > 0) ? facto*i : 1;
    
    return facto;    
}

//------------------------------------------------------------------------------
// functions to calculate the m^n power
// recursive definition: (m*m*m*m*m* ... n-1 times)*m time
// power of m^n power(m,n-1)*m
//------------------------------------------------------------------------------
unsigned long long m_power_n_recursion(int m, int n){
    
    unsigned long long power {1};
    power = (n > 0) ?  m_power_n_recursion(m,n-1)*m : 1;
    
    return power;
}
unsigned long long m_power_n_loop(int m, int n){
    
    unsigned long long power {1};
    for (int i {0}; i <=n; ++i)
        power = (i > 0) ?  power*m : 1;
        
    return power;
}
unsigned long long m_power_n_cmath(int m, int n){
            
    return std::pow(m,n);
}

//------------------------------------------------------------------------------
// functions to calculate e^x with the Taylor Series, using n terms
// Taylor Series: e^x = 1 + x/!1 + x^2/2! + x^3/3! + x^4/4! + ... + x^n/n!
//------------------------------------------------------------------------------
double taylor_recursion(int x, int p){
    double power{}, facto{}, term{};
    
    if (p > 0){
        term = taylor_recursion(x, p-1);
        power = m_power_n_recursion(x,p);
        facto = factorial_recursion(p);
        return term + power/facto;
    }
    else{
        return 1;
    }
    
}
double taylor_loop(int x, int p){
    double power{1}, facto{1}, term {1};
    
    for (int i{1}; i <= p; ++i){
        power *= x;
        facto *= i;
        term += power/facto;
    }
    
    return term;
}

//------------------------------------------------------------------------------
// functions to calculate the fibonacci series up to n
// recursive definition: 1,1,2,3,5,8,13,21,....n = 
// fibonacci of n = (n-2)+(n-1)
//------------------------------------------------------------------------------
int fibonacci_recursion(int n){
    if (n <= 1)
        return n;
    //a recrusive function that may call that may call itself with the same
    //parameters multiple times is knows as excessive recursion
    //memoization solves the problem
    return fibonacci_recursion(n-2) + fibonacci_recursion(n-1);
}
int fibonacci_memoization(int n, int lookup[]){
//memiozation stores values of previous calls to speed up processing
//the first thing the function does is check for a value of (fibo[n])
//before making another recursive call

    if (lookup[n] != -1)
        return lookup[n];
    
    if (n <= 1){
        lookup[n] = n;
        return n;
    }
    else {
        if (lookup[n-2] == -1){
           lookup[n-2] = fibonacci_memoization(n-2, lookup);
        }
        if (lookup[n-1] == -1){
           lookup[n-1] = fibonacci_memoization(n-1, lookup);
        }
        return fibonacci_memoization(n-2, lookup) + fibonacci_memoization(n-1, lookup);
    }
}
int fibonacci_loop(int n){
    int term1{0}, term2{1}, fibo{0};
    
    if (n <= 1)
        return n;
        
    for (int i{2}; i <= n; ++i){
        fibo  = term1 + term2;
        term1 = term2;
        term2 = fibo;
    }
    
    return fibo;
}

//------------------------------------------------------------------------------
// functions to calculate nCr combination formula nCr = n!/(r!(n-r)!
// n = total number of choices (e.g. 12 pizza topings)
// r = size of desired group (e.g., choose 2 of the 12 toppings)
//------------------------------------------------------------------------------
int nCr_recursion(int n, int r){
    //look up Pascal's triangle for full understanding of this function
    
    if (r == 0 || n == r)
        return 1;
    else
        return nCr_recursion(n-1, r-1) + nCr_recursion(n-1,r);

}
int nCr_factorial_calcs(int n, int r){
    unsigned long long nFact{0}, rFact{0}, nrFact{0};
    
    nFact = factorial_loop(n);
    rFact = factorial_loop(r);
    nrFact = factorial_loop(n-r);    
    
    return nFact/(rFact*nrFact);
}

//------------------------------------------------------------------------------
// functions to solve the Tower of Hanoi problem - move all the disks from 
// tower A to tower C, one at a time, while never stacking a larger disc on top
// of a smaller disc 
//       -|-           |            |           |            |            |
//      --|--          |            |           |            |            |
//     ---|---         |            |        ---|---       --|--         -|-
//        A            B            C           A            B            C
//   ---------------starting-----------    ---------------two moves-----------
//------------------------------------------------------------------------------
void tower_of_hanoi(int n,char A, char B, char C){
    if(n>0){
        tower_of_hanoi(n-1,A,C,B);
        std::cout << "Moving disc " << n << " from tower " << A << " to tower " << C << "\n";
        tower_of_hanoi(n-1,B,A,C);
    }
}

#endif //_RECURSION_HPP_