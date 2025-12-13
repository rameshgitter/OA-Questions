# 🚀 HackerEarth Runtime Error Guide

> **A clean, contest‑ready reference to quickly identify, debug, and fix runtime errors on HackerEarth.**

---

## 📌 Why This Guide?

Runtime Errors (RE) are among the most frustrating issues in competitive programming—your code compiles, but crashes at execution. This guide helps you **identify the exact cause**, **apply quick fixes**, and **avoid REs altogether** during contests.

---

## 📚 Table of Contents

1. [What is a Runtime Error?](#-what-is-a-runtime-error)
2. [Common Runtime Errors](#-common-runtime-errors)
3. [Best Practices to Avoid Runtime Errors](#-best-practices-to-avoid-runtime-errors)
4. [Quick Debugging Checklist](#-quick-debugging-checklist)
5. [Memory Limits Reference](#-memory-limits-reference)
6. [Quick Fix Examples](#-quick-fix-examples)
7. [Support](#-support)

---

## ❓ What is a Runtime Error?

A **Runtime Error (RE)** occurs when:

* Your program **compiles successfully**, but
* **Crashes or terminates abnormally during execution**

This usually happens due to **illegal memory access**, **invalid operations**, or **resource overuse**.

---

## ❌ My Program Doesn’t Compile — Why?

Compilation errors happen **before execution** and usually mean the judge compiler rejected your code due to **non-standard features, unsupported libraries, or language-specific constraints**.

---

### 🧩 C / C++ Compilation Issues

✔ **Use standard-compliant compilers**
HackerEarth uses **modern GCC/Clang**, not legacy compilers.

❌ **Avoid Turbo C++ specific code**

```cpp
#include <conio.h>   // ❌ Not supported
clrscr();
getch();
```

✅ **Use standard headers instead**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
```

🔴 Common C/C++ Compile Errors:

* Using `conio.h`, `dos.h`, or Turbo C++ functions
* Relying on compiler-specific extensions
* Missing headers (`#include <bits/stdc++.h>` is allowed, but not portable)
* Mismatched function signatures

---

### ☕ Java Compilation Issues

✔ **Multiple classes are supported**
✔ **Inner classes must be `static`** (for now)

❌ **This may fail**

```java
class Outer {
    class Inner { }
}
```

✅ **Correct approach**

```java
class Outer {
    static class Inner { }
}
```

🔴 Common Java Compile Errors:

* Inner classes not declared `static`
* Class name does not match file name
* Missing `public static void main(String[] args)`
* Using unsupported Java versions or APIs

⚠️ **Note:** This `static inner class` restriction will be removed soon. HackerEarth will announce the update.

---

## ⚠️ Common Runtime Errors

| Error Code  | Name                  | Meaning                    | Frequent Causes                                                     |
| ----------- | --------------------- | -------------------------- | ------------------------------------------------------------------- |
| **SIGSEGV** | Segmentation Fault    | Invalid memory access      | Out‑of‑bounds array access, uninitialized pointers, buffer overflow |
| **SIGXFSZ** | Output Limit Exceeded | Too much output            | Infinite printing, excessive debug logs                             |
| **SIGFPE**  | Floating Point Error  | Invalid arithmetic         | Division by zero, modulo by zero, overflow                          |
| **SIGABRT** | Aborted               | Forced termination         | Assertion failure, stack overflow, memory exhaustion                |
| **NZEC**    | Non‑Zero Exit Code    | Program exited incorrectly | Missing `return 0`, uncaught exceptions, runtime crash              |
| **MLE**     | Memory Limit Exceeded | Memory usage too high      | Large arrays, memory leaks, oversized containers                    |
| **OTHER**   | Miscellaneous         | Undefined failures         | Combination of memory and execution issues                          |

---

## ✅ Best Practices to Avoid Runtime Errors

### 🧠 Memory Management (C/C++)

```cpp
// ❌ BAD: Extremely large stack allocation
int arr[100000][100000];

// ✅ GOOD: Declare large arrays globally
int arr[1000000];

int main() {
    return 0;
}
```

✔ Avoid large stack allocations
✔ Prefer heap or global memory
✔ Keep memory under platform limits (64–256 MB)

---

### 📏 Safe Array Access

```cpp
if (i >= 0 && i < n) {
    arr[i] = value;
}
```

✔ Always validate indices
✔ Never assume valid input indices
✔ Watch out for negative indices

---

### 🔄 Variable Initialization

```cpp
// ❌ BAD
int x;  // garbage value

// ✅ GOOD
int x = 0;
```

✔ Initialize all variables
✔ Especially counters, flags, and accumulators

---

### ➗ Arithmetic Safety

```cpp
if (denominator != 0) {
    result = numerator / denominator;
}
```

✔ Guard division and modulo operations
✔ Handle edge cases explicitly

---

### 🧾 Proper Program Exit

```cpp
int main() {
    // logic
    return 0;
}
```

✔ Prevent NZEC errors
✔ Always return 0 in C/C++

---

## 🐍 Python‑Specific Tips

```python
# Safe input handling
try:
    x = int(input())
except Exception:
    x = 0

# Safe division
if denom != 0:
    res = num / denom
```

✔ Catch exceptions properly
✔ Avoid unsupported external libraries
✔ Watch recursion depth (`sys.setrecursionlimit`)
✔ Avoid infinite loops producing output

---

## 🧪 Quick Debugging Checklist

Before submitting again, verify:

* [ ] All variables initialized
* [ ] No array out‑of‑bounds access
* [ ] No division/modulo by zero
* [ ] `return 0` present in `main()`
* [ ] Array sizes within limits
* [ ] Large arrays declared globally
* [ ] Exceptions handled (Python)
* [ ] No infinite output loops

---

## 💾 Memory Limits Reference

| Resource     | Typical Limit              |
| ------------ | -------------------------- |
| Total Memory | 64 – 256 MB                |
| Stack        | ~8 MB                      |
| Heap         | Remaining available memory |

⚠️ Stack overflow is a **very common** cause of RE

---

## 🔧 Quick Fix Examples

### 🚨 SIGSEGV

```cpp
// ❌ Before
int a[100];
a[100] = 5;  // invalid

// ✅ After
if (idx < 100) {
    a[idx] = 5;
}
```

---

### 🚨 NZEC

```cpp
// ❌ Before
int main() {}

// ✅ After
int main() {
    return 0;
}
```

---

### 🚨 MLE

```cpp
// ❌ Stack allocation
int main() {
    int arr[1000000];
}

// ✅ Global allocation
int arr[1000000];
int main() {}
```

---

## 📞 Support

For platform‑specific issues, contact **HackerEarth Support**:

📧 **[support@hackerearth.com](mailto:support@hackerearth.com)**

---

## 🌟 Contribute

* ⭐ Star this repository if it helped you
* 🛠 Open issues for missing cases
* 🔀 Submit PRs to improve explanations

---

### 🎯 Final Tip

> **90% of Runtime Errors come from just 3 things:**
> **out‑of‑bounds access, division by zero, and memory misuse.**

Master these—and REs will fear *you*.

**Happy Coding! 💻🔥**
