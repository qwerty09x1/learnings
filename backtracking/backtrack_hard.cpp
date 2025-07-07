#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef vector<int> vi;

//Generate Balanaced Parenthesis
//Generate all valid combinations of N pairs of parenthesis. 

//Coin change combinations 
//Given coins of different combinations and a target amount, find all combinations that make the target amount. You can use each coin multiple times.
//Write every combination in increasing manner 
void coinchangecomb(vector<int>& coins, int target, vector<int>& curr, int index) {
    int sum = accumulate(curr.begin(), curr.end(), 0);
    //base
    if (sum == target) {
        for (int coin : curr) cout << coin << " ";
        cout << endl;
        return;
    }
    //controlled recurion
    if (sum > target) return;
    //choices 
    for (int i = index; i < coins.size(); i++) {
        curr.push_back(coins[i]);
        coinchangecomb(coins, target, curr, i);  // Reuse same coin
        curr.pop_back();  // Backtrack
    }
}
void solvecoinchangecomb() {
    int n, target;
    cin >> n >> target;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    sort(coins.begin(), coins.end());  // Sort to ensure increasing order

    vector<int> curr;
    coinchangecomb(coins, target, curr, 0);
}
//Permutation of a string
void permut(string &s, vector<bool> &used, string &op) {
    if(op.size() == s.size()) {
        cout << op << endl;
        return;
    }

    for(int i = 0; i < s.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            op.push_back(s[i]);
            permut(s, used, op);
            op.pop_back();
            used[i] = false;
        }
    }
}
void solvepermut() {
    string s;
    cin >> s;
    string op = "";
    vector<bool> used(s.size(), false);
    permut(s, used, op);
}
//Partition into k groups> Given n numbers, find all ways to partition them into exactly k nonempty groaups. just give the count.
void partition(vector<int> &v, int index, int n, int k, int &count, vector<vector<int>> &curr) {
    if (index == n) {
        if (curr.size() == k) {
            count++;
        }
        return;
    }
    // Try putting v[index] into any existing group
    for (int i = 0; i < curr.size(); i++) {
        curr[i].push_back(v[index]);
        partition(v, index + 1, n, k, count, curr);
        curr[i].pop_back();  // backtrack
    }
    // Try putting it in a new group (only if we haven't created k groups yet)
    if (curr.size() < k) {
        curr.push_back({v[index]});
        partition(v, index + 1, n, k, count, curr);
        curr.pop_back();  // backtrack
    }
}
void solvePartition() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<vector<int>> curr;
    int count = 0;
    partition(v, 0, n, k, count, curr);
    cout << count << endl;
}
//Partition sum > given an array, find all ways to partition it into two subsets with equal sum. print only if such partition exists.
void partitionsum(){

}
void solvePartitionSum(){
    int n;
    cin>> n;
    
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solvePartitionSum();
    return 0;
}

