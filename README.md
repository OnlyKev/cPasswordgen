# Password Generator
[Kevin Wahome]
[11/19/23]

## Description

This is a simple C program that allows users to generate passwords interactively. 
The program provides options for users to either manually specify the number of digits, uppercase letters, lowercase letters, and special characters in the password 
or let the program generate a random password.

## Features

- Password generation based on user-specified criteria or random generation.
- Use of a `Password` struct to encapsulate password-related information.
- Modular structure with functions for initialization and password generation.
- Randomness factor for additional variability in password generation.
- User-friendly interface with input validation.

## Getting Started

### Prerequisites

- C compiler (e.g., GCC)

### Usage

Clone the repository:

   ```bash
   git clone https://github.com/OnlyKev/password-generator.git
   ```
1. Compile the program
```bash
  gcc password_generator.c -o password_generator
  ```

3. Run the executable
```bash
  ./password_generator
```

5. Follow the on-screen prompts to generate passwords

### Usage Examples

Generates Passwords Randomly

   ./password_generator

Generate Passwords with User Specifications

   ./password_generator
   
1

5 4 3 2

Note:
The program uses 'scanf' for input, which may have potential buffer overflow issues. Consider using a safer alternative like 'fgets' for input





