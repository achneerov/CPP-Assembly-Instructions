# C++ Inline Assembly Example

This project demonstrates how to embed assembly language code within C++ using GCC/Clang's inline assembly syntax. The program showcases basic operations such as addition, multiplication, and looping, all implemented with inline assembly.

## Features

- **Addition**: Adds two integers using assembly instructions.
- **Multiplication**: Multiplies two integers using assembly instructions.
- **Looping**: Sums the numbers from 1 to 10 using a loop implemented in assembly.

## Prerequisites

- **GCC** or **Clang** compiler (supports inline assembly)
- A C++ development environment

## Files

- `main.cpp`: The main C++ file containing the program logic with embedded assembly instructions.

## Compilation

To compile the program, use the following commands depending on your compiler:

### Using GCC or Clang:

```bash
g++ -o assembly_example main.cpp
./assembly_example
```

## Code Explanation

The code demonstrates inline assembly through the following key functions:

### 1. **add_in_assembly()**  
Adds two integers `a` and `b` using the `addl` instruction in assembly and stores the result in a C++ variable.

### 2. **multiply_in_assembly()**  
Multiplies two integers `a` and `b` using the `imull` instruction and stores the result in a C++ variable.

### 3. **loop_in_assembly()**  
Sums the numbers from 1 to 10 using a loop written in assembly. The loop is implemented using `addl`, `incl`, and `cmpl` instructions.

### Key Assembly Instructions:
- `movl`: Moves data between registers or from memory to registers.
- `addl`: Adds the values in registers.
- `imull`: Multiplies values in registers.
- `cmpl`: Compares values in registers.
- `incl`: Increments a register value.
- `jl`: Jumps to a label if the comparison indicates the condition is met.

### Inline Assembly Syntax (GCC/Clang)
- The `asm` keyword is used for embedding assembly code.
- Registers are prefixed with `%%` (e.g., `%%eax`).
- Output operands are specified with `=r` for a register and input operands with `r` for a register.
- The clobbered registers are indicated in the last section of the `asm` statement to inform the compiler that these registers will be modified.

## Example Output

```bash
C++ with Inline Assembly Example
Result of addition (a + b): 8
Result of multiplication (a * b): 24
Sum of numbers from 1 to 10: 55
```

