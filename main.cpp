//  CSC382_Compare-Fibonacci
//  Created by Roman Petlyak on 1/25/24.
#include <iostream>
#include "ctime"
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

float Recursive(int n);
float nonRecursive(int n);
float MODFibR(int n);

int main() {
    int testCases[] = {1, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60};

    std::cout << left << setw(12) << "Integer" << setw(20) << "FiboR(seconds)" 
              << setw(20) << "MODFibR(seconds)" << setw(20) << "FiboNR(seconds)" 
              << setw(20) << "Fibo-value" << endl;
    
    for (int i = 0; i < sizeof(testCases); ++i) {
        int n = testCases[i];
        clock_t start, end;
        double fiboR_time, modFibR_time, fiboNR_time;

        // Timing FiboR
        start = clock();
        Recursive(n);
        end = clock();
        fiboR_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

        // Timing MODFibR
        start = clock();
        int fiboValue = MODFibR(n);
        end = clock();
        modFibR_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

        // Timing FiboNR
        start = clock();
        nonRecursive(n);
        end = clock();
        fiboNR_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

        std::cout << std::left << std::setw(12) << n 
                  << std::setw(20) << std::setprecision(6) << fiboR_time 
                  << std::setw(20) << std::setprecision(6) << modFibR_time 
                  << std::setw(20) << std::setprecision(6) << fiboNR_time 
                  << std::setw(20) << fiboValue << std::endl;
    }
    return 0;
}
// Fibonaci non recursive approach
float nonRecursive(int n) {
    int F[100];
    F[0] = 0; F[1] = 1;
    for(int i = 2; i <= n; i++){
        F[i] = F[i-1] + F[i-2];
    }
    return F[n];
}
// Fibonaci recursive approach
float Recursive(int n) {
    if(n == 0 || n == 1){ return(n); }
    else{ return (Recursive(n-1) + Recursive(n-2)); }
}
//MODfibR function
float MODFibR(int n) {
    // Initialize memoization array with -1, indicating uncalculated values
    std::vector<int> mod(n + 1, -1);
    
    mod[0] = 0;
    if (n > 0) mod[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (mod[i] == -1) { // Check if the value has not been calculated yet
            mod[i] = mod[i-1] + mod[i-2]; // Calculate and store for future reference
        }
    }
    return mod[n];
}