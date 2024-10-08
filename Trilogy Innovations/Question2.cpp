/*
Welcome to the magical world of Mario's adventure where Mario is standing on platform 0 and needs to reach platform A + 1.
But oh no, there's a wide river that's A units wide blocking his way. 
Mario can't walk on water, but he's got an amazing ability he can jump up to B units at a time, either forward or backward.

On the river, there are various-sized wooden platforms floating on the river just like in Mario's games. 
In total there are M platforms and their sizes are stored in an integer array C. 
Mario can move these platforms around, but he can't change their order or let them overlap. 
Note that he should first move the platforms and then start his journey. Help Mario cross the river and reach platform A + 1

If it is impossible to reach A + 1 your answer will be a vector containing -1, acknowledging the challenge. 
Yet, if a solution exists, return a vector of size A representing the sequence of river cells. 
It cell i does not belong to any platform, the ith element of the answer veckor should be 0. 
Otherwise, it should be equal to the index of the platform to which the cell i belongs. 
If there are multiple solutions return the lexicographically smallest one. 

Problem Constraints
1 <= A <= 10 ^ 5
1 <= B <= 10 ^ 5
1 <= M <= A
1 <=C[|]<=A
Sigma*C[i] <= A

Input Format
The first argument is an integer A
The second argument is an integer B
The third argument is an integer array C

Output Format
Return an integer array representing the answer.

Example Input

Input 1	: A = 7 , B = 2 , C = [1, 2, 1]				 |    Input 2: A = 1 * 0 B = 5 C = [2]
Output1	:  [0, 1, 0, 2, 2, 0, 3]					 |    Output2: [0, 0, 0, 1, 1, 0, 0, 0, 0]

Example Explanation
The sequence of jumps Mario performs is 0-2-4-5-7-8. |    The sequence of jumps you perform is 0-5-6-11
*/


