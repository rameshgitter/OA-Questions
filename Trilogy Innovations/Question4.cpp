/*
There are some job opportunities in one company. 
And there are some candidates for these jobs. 
Candidate can be hired for the ith job if he has all skills that are needed for this job. 
There are some distinct skills which can be needed for jobs. 
Company needs only one person for each job. 
Moreover each candidate can be hired only for one job and the profit of hiring somebody for the ith job is profits[i]. 
Profit of hiring for the set of jobs equals to sum of profits of each job in set. 
For the empty set it's 0.

Your task is to calculate a maximum profit after hiring a subset of candidates for a subset of jobs.

Example

For profits = [4, 10] skillsForJobs = [[true, false], [false, true]], and skillsOfCandidates = [[true, true], [true, false]], 
the output should be solution(profits, skillsForJobs, skillsofCandidates) = 14;

For profits = [5] skillsForJobs = [[true]], and skillsofCandidates = [[true]] 
the output should be solution(profits, skillsForJobs, skillsof Candidates) = 5

Input/Output
[execution time limit] 0.5 seconds (cpp)
*/

