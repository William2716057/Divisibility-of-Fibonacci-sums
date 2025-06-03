# Fibonacci Modulo Divisibility Checker

This C script determines whether the sum of Fibonacci numbers from F<sub>a</sub> to F<sub>b</sub> (inclusive) is divisible by a given integer `d`. It uses fast matrix exponentiation for efficient computation, even for large values of `a` and `b`.

## 🔧 Features

- Computes Fibonacci numbers modulo `d` using matrix exponentiation
- Efficient for very large indices
- Accepts multiple test cases in a single run

## 🧠 Formula

To compute the sum of Fibonacci numbers from F<sub>a</sub> to F<sub>b</sub>, we use the identity:

F_a + F_{a+1} + ... + F_b = F_{b+2} - F_{a+1}

We calculate this modulo `d`.

## 📥 Input Format

1. The number of test cases, `n`
2. For each test case, three integers:
   - `a`: start index
   - `b`: end index
   - `d`: divisor

### Example Input

1. Enter number of test cases: 2
2. Enter values for a, b and d (space separated): 2 5 3
3. Enter values for a, b and d (space separated): 1 4 5

