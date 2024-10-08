/*
Problem Description

You are given two matrices, X and Y, both of size M*M filled with either +1 or -1 values. 
Initially, you do not have complete information about the matrices X and Y. 
You are given N unique queries in the form of a 2D array A with N rows and 4 columns. 
For each query, consider x = A[1][0] and y = A[i][1] 
Then A[i][2] represents the value at the x-th row and y-th column in matrix X, 
while A[i][3] represents the value at the same position in matrix Y. 

After each query, you need to determine if it is possible to convert matrix X into matrix Y using the following operations: 
1. Multiply an entire row of X by -1. 2. Multiply an entire column of X by -1.
 
Your goal is to determine whether it is possible to convert X into Y using these operations. 
If it is possible to convert X into Y, return "Yes". Otherwise, return "No". 

Problem Constraints 
M = 10 ^ 18 1 <= N <= 10 deg * 5 
• 1 <= A[i][0] A[i][1] <= 10 ^ 18 
• A[1][2], A[i][3] belong to \{- 1, 1\} 
• If A[i][0] ==A[il[0] then A[i] * [1]! = A[i][1] If A[i][1] ==A[i][1] then A[i] * [0]! =A[i][0] 

Input Format 
•First and the only argument contains a 2D array of integers A. 

Output Format 
Return an array of strings, representing the result of each query. 
• Let's say the array of strings is R then R[i] can only be "Yes" or "No" depending upon the result of the i-th query. 
  
Example Input  
Input 1: A=[1, 1, 1, 1], [1, 2, 1, -1]] 
Input 2: A= [[1, 1, 1, 1], [1, 2, 1, 1], [2, 2, 1, 1], [2, 1, 1, -1]] 

Example Output 
Output 1: Yes Yes 
Output 2: Yes Yes Yes No 

Explanation For Input 1: 
After 1st query, X can directly be converted to Y as X[1][1] = Y[1][1], and we can assume all other cells are also the same. 
After 2nd query, if we multiply the 2nd column of X with -1 then we get X[1][1] = Y[1][1] (from previous query) and X[1][2] = Y[1][2] (after multiplying 2nd column with -1, X[1][2] also become -1) 
Hence for both queries, it is possible to convert X into Y 

For Input 2: 
For queries 1st, 2nd, and 3rd no operation is required. 
X can directly be converted to Y. After the 4th query it is not possible to convert X into Y by using any of the given operations. 

[execution time limit] 0.5 seconds (cpp) 
*/

