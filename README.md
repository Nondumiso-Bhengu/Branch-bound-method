# Branch-bound-method
30462533 NP BHENGU
27527204 A MLAMBO
29875846 D MOKHASINYANE

The code shows the implementation of the branch and bound method for a knapsack problem. 

the code was implemented on code blocks but should work on any other c++ compiler.

with the branch and bound, we are trying to find out the maximum profit that each tutor will get for the time period that they have worked

this method creates a tree that involves subsets of the solution set & identifies branches (nodes) of the tree. it then checks every node's LP relaxation by using an estimated upper and lower bound on the variables. if the current solution is worse than the preceding one, then the branch is discarded and it continues exploring other branches till the optimal solution is found.
