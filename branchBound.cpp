//REII PRACTICAL 2020
//GROUP MEMBERS: N Bhengu (30462533), A Mlambo (27527204), D Mokhasinyane (29875846)

#include <iostream>
//#include <math.h>
//#include <algorithm>
//#include <winuser.h>
#include <bits/stdc++.h>

using namespace std;

struct tutor
{
    //take the timeWorked as the weight on the nodes that will be used to check the knapsack capacity
    double timeWorked;
    int value;
};

struct node
{
    double timeWorked;
    int profit;
    int bound;
    int branch;
};
//compare the tutor's payment according to the time that they worked & the value of the work done
bool compare(tutor A, tutor B )
{
    double tutorARatio = (double)A.value/ A.timeWorked;
    double tutorBRatio = (double)B.value/ B.timeWorked;
    return tutorARatio > tutorBRatio;
}
//here the function must return a bound of profit from the node (a), and the upper bound will be on the max. profit
// m represents the knapsack capacity, a represents current
int bound(tutor arr[], node a, int n, int m)
{
  //if the timeWorked(weight)> knapsack capacity, then return 0 for the expected bound
  if (a.timeWorked>= m)
        return 0;

  int boundProfit = a.profit; //here the bound profit is made equal to the current profit
  //include the tutors from an index that is 1 greater than the current tutor index
  //i represents the index
  int i = a.branch+1;
  int tottimeWorked= a.timeWorked;
  //compare the condition of the index to the knapsack capacity condition
  while ((i<n)&&(tottimeWorked + arr[i].timeWorked<=m))
  {
      tottimeWorked=arr[i].timeWorked;
//boundProfit=arr[i].timeWorked;
      boundProfit=arr[i].value;
      i++;
  }
  if(i<n)
    boundProfit=(m-tottimeWorked)*(arr[i].value/arr[i].timeWorked);
  return boundProfit;
}
int knapsack(int m, tutor arr[], int n)
{
    sort(arr, arr+n, compare); //sorting the tutors based on the value of the content taught at a given time
    queue <node> Q; //create a queue for the traversing node
    node a, p;
  //a.branch=+1;
    a.branch =-1;
    a.profit =a.timeWorked=0;
    Q.push(a);
    //tutors will be extracted from the decision tree and their profit will be calculated
    int maximimumProfit;
    while (!Q.empty())
    {
        a = Q.front(); //to dequeue a node
        Q.pop();

        if (a.branch == -1) //if it is a starting node, then assign the value 0 to the branch
            p.branch = 0;

        if (a.branch == n-1) // if there is nothing on the following branch, you must continue with the process
            continue;
        //if it is not the last node, then you must increment the branch 7 calculate the profit at the child nodes
        a.branch = a.branch +1;
        //take the current branch's tutor and add the current branch's timeWorked & value to node a's timeWorked & value
        p.timeWorked = a.timeWorked + arr[p.branch].timeWorked;
        p.profit = a.profit + arr[p.branch].value;

    if (p.timeWorked<=m&&p.profit>maximimumProfit) //updating the max profit
            maximimumProfit = p.profit;
//    p.bound = bound(p,n,m,arr);
    //if the bound value is > profit, then only push the queue to continue
    if (p.bound> maximimumProfit)
        Q.push(p);

    p.timeWorked = a.timeWorked;
    p.profit = a.profit;
//    p.bound =  bound(p,n,m,arr);

    if (p.bound > maximimumProfit)
        Q.push(p);
    }
    return maximimumProfit;
}
int main()
{
    cout << "Testing of the branch and bound method using knapsack" << endl;
    int m = 20;
    //double k; //for knapsack
    tutor arr[] = {{1,30},{2.2,40},{3.4,90},{4,80},{5.2,20}};
    int n =sizeof (arr)/ sizeof(arr[0]);
cout<<"\nThe max profit that each tutor will get is = "<< knapsack(m, arr, n);
    return 0;
}
