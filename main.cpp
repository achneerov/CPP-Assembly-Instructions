#include <iostream>

using namespace std;

void add_in_assembly() {
    int a = 5, b = 3, result;
    
    // Inline Assembly to add two integers for GCC/Clang
    asm(
        "movl %[a], %%eax;"   // Move the value of 'a' into eax register
        "addl %[b], %%eax;"   // Add the value of 'b' to eax
        "movl %%eax, %[result];"  // Move the result from eax into 'result'
        : [result] "=r" (result)  // output
        : [a] "r" (a), [b] "r" (b)  // inputs
        : "%eax"   // clobbered register
    );

    cout << "Result of addition (a + b): " << result << endl;
}

void multiply_in_assembly() {
    int a = 4, b = 6, result;

    // Inline Assembly to multiply two integers for GCC/Clang
    asm(
        "movl %[a], %%eax;"   // Move 'a' into eax
        "imull %[b], %%eax;"  // Multiply eax by b (result in eax)
        "movl %%eax, %[result];" // Move result into 'result'
        : [result] "=r" (result)  // output
        : [a] "r" (a), [b] "r" (b)  // inputs
        : "%eax"   // clobbered register
    );

    cout << "Result of multiplication (a * b): " << result << endl;
}

void loop_in_assembly() {
    int sum = 0;

    // Inline Assembly to sum the numbers from 1 to 10 for GCC/Clang
    asm(
        "movl $1, %%ecx;"      // Initialize counter (ecx = 1)
        "movl $0, %%eax;"      // Clear eax (accumulator for sum)
        "loop_start:"
        "addl %%ecx, %%eax;"   // Add counter value to eax
        "incl %%ecx;"          // Increment counter
        "cmpl $11, %%ecx;"     // Compare counter with 11
        "jl loop_start;"       // Jump if counter is less than 11
        "movl %%eax, %[sum];"  // Move result to 'sum'
        : [sum] "=r" (sum)      // output
        :                       // inputs
        : "%eax", "%ecx"        // clobbered registers
    );

    cout << "Sum of numbers from 1 to 10: " << sum << endl;
}

int main() {
    cout << "C++ with Inline Assembly Example" << endl;

    add_in_assembly();
    multiply_in_assembly();
    loop_in_assembly();

    return 0;
}
