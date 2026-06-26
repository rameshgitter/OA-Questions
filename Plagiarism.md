# How Plagiarism Detection Works in HackerRank and Other Online Assessments

> **Note:** This document is for educational purposes only. The exact plagiarism detection methods used by HackerRank and individual companies are proprietary and are not publicly disclosed.

---

## Overview

Most online assessment platforms (HackerRank, CodeSignal, Codility, etc.) use plagiarism detection systems to identify submissions that are unusually similar.

The goal is to detect copied code while allowing independent solutions that naturally use the same algorithm.

---

## Techniques Commonly Used

### 1. Code Normalization

Before comparing submissions, platforms normalize the code by removing differences such as:

- Whitespace
- Indentation
- Comments
- Blank lines
- Variable names (or reducing their importance)

Example:

```cpp
int sum = 0;
for (int i = 0; i < n; i++)
    sum += arr[i];
```

```cpp
int ans = 0;
for (int j = 0; j < n; j++)
    ans += nums[j];
```

Although different textually, these are structurally very similar.

---

### 2. Token-Based Comparison

The source code is converted into tokens.

Example:

```cpp
for(int i=0;i<n;i++)
```

becomes something similar to

```
FOR
(
INT
IDENTIFIER
=
NUMBER
;
IDENTIFIER
<
IDENTIFIER
;
IDENTIFIER
++
)
```

Similarity is measured on these token sequences rather than raw text.

---

### 3. Abstract Syntax Tree (AST)

Many systems compare the program structure rather than the exact syntax.

Example:

```cpp
if(a > b)
    return a;
else
    return b;
```

and

```cpp
return a > b ? a : b;
```

look different but represent similar logic.

---

### 4. Structural Similarity

The detector may compare:

- Loop structure
- Branching
- Function organization
- Control flow
- Data flow
- Overall implementation pattern

Changing only variable names usually has little effect.

---

### 5. Pairwise Comparison

Every submission can be compared with:

- Other candidates
- Previous assessment submissions
- Public repositories
- Known solution databases

High similarity scores may trigger manual review.

---

### 6. Behavioral Signals (Optional)

Depending on assessment settings, employers may collect:

- Copy/paste events
- Typing activity
- Time spent solving
- Browser focus changes
- Submission timing

Not every assessment enables these features.

---

## What Usually Does NOT Avoid Detection

Changing only:

- Variable names
- Function names
- Comments
- Formatting
- Indentation

is generally insufficient.

---

## What Is Usually Acceptable

Independent implementations of standard algorithms are expected.

Examples include:

- Binary Search
- BFS
- DFS
- Dynamic Programming
- Two Pointers
- Sliding Window
- Union Find
- Greedy Algorithms

Many candidates naturally arrive at similar high-level approaches.

---

## Best Practices

- Solve problems independently.
- Understand every line of code you submit.
- Avoid copying from others or public repositories during an assessment.
- Be prepared to explain your solution in follow-up interviews.
- Follow the rules specified by the employer or assessment platform.

---

## Disclaimer

This document summarizes publicly known techniques used in plagiarism detection systems. The actual implementation and thresholds used by HackerRank or individual companies are proprietary and may differ.
