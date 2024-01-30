//
//  main.cpp
//  csc382_project1
//
//  Created by Roman Petlyak on 1/25/24.
//

#include <iostream>
#include "ctime"
#include <cmath>

using namespace std;
using namespace std::chrono;

float Rec(int n);
float nonRec(int n);
void menu();
float MODfibR(int n);

int main(int argc, const char * argv[]) {
    
    int n = 800000;
    
    clock_t start = clock();
    int fib = nonRec(n);
    clock_t finish = clock();
    double exec_time = (double)(finish - start) / CLOCKS_PER_SEC;
    
    cout << "Input Size: " << n << "\n"
    << "Execution Time: " << exec_time << " seconds" << endl;
    
    return 0;
}
// Fibonaci non recursive approach
float nonRecursive(int n) {
    
    int F[n];
    F[0] = 0; F[1] = 1;
    
    for(int i = 2; i <= n; i++){
        F[i] = F[i-1] + F[i-2];
    }
    return F[n];
}

// Fibonaci recursive approach
float Recursive(int n) {
    if(n == 0 || n == 1){
        return(n);
    }
    else{
        return (Rec(n-1) + Rec(n-2));
    }
}
//MODfibR function

//Selection function
void menu() {
    
    int UserInput;
    do {
        cout << "Select the Algorithm" << endl;
        cout << "1. Recursive" << endl;
        cout << "2. Non - Recursive" << endl;
        cin >> UserInput;
    } while(UserInput != 1 || UserInput != 2);
}
