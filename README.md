# Console Calculator in C

A simple command-line calculator for evaluating arithmetic expressions with integers. Supports operations: `+`, `-`, `*`, `/`, and parentheses `()`.

## Compilation

1. Save the code to a file named `main.c`.
2. Compile the program using GCC:
   ```bash
   gcc -o calc.exe main.c
    ```
## Usage

Pipe your arithmetic expression to the program and redirect the output to a file:
```bash
echo "expression" | ./calc.exe > result.txt
```
## Examples:

```bash
echo "3 + 4 * 2" | ./calc.exe          # Output: 11
echo "(3 + 4) * 2" | ./calc.exe        # Output: 14
echo "20 / 3" | ./calc.exe             # Output: 6 (integer division)
echo "7 / -3" | ./calc.exe             # Output: -2 (truncated toward zero)
```
## Features

- **Operator precedence:** Multiplication/division prioritized over addition/subtraction.
- **Parentheses:** Supports nested parentheses e.g., `((1 + 2) * (3 - 4))`.
- **Integer arithmetic:** All operations use integer math (no floating-point support).

## Limitations

- **Integer-only:** Floating-point numbers are not supported.
- **No error handling:** Program expects valid input:
    - All parentheses must be properly balanced.
    - Division by zero causes undefined behavior.
    - Invalid characters (non-digits, unsupported operators) will crash the program.
    - No spaces allowed in numbers (e.g., `1 000` is invalid).
