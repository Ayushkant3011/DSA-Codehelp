#include<iostream>
#include<vector>
using namespace std;

/* Q. Painting fence Algorithm
int solveUsingRec(int n,int k){
    // base case 
    if(n == 1){
        return k;
    }
    if(n == 2){
        return (k + k*(k-1));
    }

    int ans = (solveUsingRec(n-1, k) + solveUsingRec(n-2,k))* (k-1);
    return ans;
}

// top down approach
int solveUsingMem(int n,int k, vector<int> &dp){
    // base case 
    if(n == 1){
        return k;
    }
    if(n == 2){
        return (k + k*(k-1));
    }
    // step 3 if already exist
    if(dp[n] != -1){
        return dp[n];
    }

    // step 2 store in dp array
    dp [n] = (solveUsingMem(n-1, k,dp) + solveUsingMem(n-2,k, dp))* (k-1);
    return dp[n];
}

//  Tabulation-> Bottom-Up Approach
int solveUsingTab(int n, int k){
    vector<int> dp(n+1, -1);
    dp[1] = k;
    dp[2] = k + k*(k-1);

    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2])*(k-1);
    }
    return dp[n];
}

// Space Optimization 
int solveUsingTabSO(int n, int k){
    // vector<int> dp(n+1, -1);
    int prev2 = k;
    int prev1 = k + k*(k-1);
    int curr;

    for(int i=3; i<=n; i++){
        curr = (prev1 + prev2)*(k-1);
        // shift
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main(){
    int n = 3;
    int k = 2;

    // step 1 
    vector<int> dp(n+1, -1);
    // int ans = solveUsingMem(n,k,dp);
    // int ans = solveUsingTab(n,k);
    int ans = solveUsingTabSO(n,k);


    // int ans = solveUsingRec(n,k);
    cout << "Ans : " << ans << endl;
    

    
    
    return 0;
}
*/

/*Q. 0/1 KnapSack Problem*/
// 2D DP
int solveUsingRec(int capacity, int wt[], int profit[], int index, int n){
    // Base Case 
    if(index == n-1){
        if(wt[index] <= capacity){
            return profit[index];
        }
        else{
            return 0;
        }
    }

    // Include/ exculde
    int indclude = 0;
    if(wt[index] <= capacity){
        indclude = profit[index] + solveUsingRec(capacity-wt[index], wt,profit, index+1, n);
    }

    int exclude = 0 + solveUsingRec(capacity, wt, profit, index+1, n);
    int ans = max(indclude, exclude);

    return ans;
}

// Memoisation
int solveUsingMem(int capacity, int wt[], int profit[], int index, int n,vector<vector<int> > &dp){
    // Base Case 
    if(index == n-1){
        if(wt[index] <= capacity){
            return profit[index];
        }
        else{
            return 0;
        }
    }

    // already exist wala case
    if(dp[capacity][index] != -1){
        return dp[capacity][index];
    }

    // Include/ exculde
    int indclude = 0;
    if(wt[index] <= capacity){
        indclude = profit[index] + solveUsingMem(capacity-wt[index], wt,profit, index+1, n,dp);
    }

    int exclude = 0 + solveUsingMem(capacity, wt, profit, index+1, n,dp);
    dp[capacity][index] = max(indclude, exclude);

    return dp[capacity][index];
}

// Tabulation
int solveUsingTab(int capacity, int wt[], int profit[], int n)
{
    vector<vector<int> > dp(capacity+1, vector<int>(n+1,-1));
    // Base Case

    for(int row=0; row<=capacity; row++){
        dp[row][n] = 0;
    }

    for(int i=0; i<= capacity; i++){
        for(int j=n-1; j>=0; j--){
            int indclude = 0;
            if(wt[j] <= i){
                indclude = profit[j] + dp[i-wt[j]][j+1];
            }
            int exclude = 0 + dp[i][j+1];    
            dp[i][j] = max(indclude, exclude);
        }
    }
    return dp[capacity][0];
}

// Space Optimization
int solveUsingTabSO(int capacity, int wt[], int profit[], int n ){
    vector<int> next(capacity+1, 0);
    vector<int> curr(capacity+1, -1);

    for(int j=n-1; j>=0; j--){
        for(int i=0; i<= capacity; i++){        
            int include = 0;
            if(wt[j] <= i){
                include = profit[j] + next[i-wt[j]];
            }
            int exclude = 0 + next[i];    
            curr[i] = max(include, exclude);
        }
        // shifting
        next = curr;
    }

    return curr[capacity];
}

int main(){
    int capacity = 6;
    int wt[] = {1,2,3};
    int profit[] = {10,15,40};
    // int index = 0;
    int n =3;

    vector<vector<int> > dp(capacity+1, vector<int>(n+1,-1));

    // int ans = solveUsingRec(capacity, wt, profit, index, n);
    // int ans = solveUsingMem(capacity, wt, profit, index, n,dp);
    int ans = solveUsingTabSO(capacity, wt, profit, n);
    cout << "Max Profit: " << ans << endl;


    return 0;
}