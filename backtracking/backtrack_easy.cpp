#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void printbinary(int length, vector<int> &curr) {
    if (curr.size() == length) {
        for (int k : curr) cout << k;
        cout << '\n';
        return;
    }

    curr.push_back(0);
    printbinary(length, curr);
    curr.pop_back();

    curr.push_back(1);
    printbinary(length, curr);
    curr.pop_back();
}

void printSubLex(string &ip, string &op, int index) {
    if (!op.empty()) {
        cout << op << endl;
    }

    for (int i = index; i < ip.size(); ++i) {
        // Only add character if it's greater than the last one added
        if (op.empty() || ip[i] > op.back()) {
            op.push_back(ip[i]);
            printSubLex(ip, op, i + 1);
            op.pop_back(); // backtrack
        }
    }
}

void generateallsubsets(int length, vector<int>v, int index,vector<int> &curr){
    for(int i=0;i<curr.size();i++){
        cout<<curr[i];
    }
    cout<<endl;
    for(int j=index;j<length;j++){
        curr.push_back(v[j]);
        generateallsubsets(length, v,j+1,curr);
        curr.pop_back();
    }

}

void subsetsum(vector<int> &arr, int n, int k, vector<int> &curr, int &count, int index) {
    int sum = accumulate(curr.begin(), curr.end(), 0);
    
    if (sum == k) {
        count++;
        // Optional: print the valid subset
        // for (int x : curr) cout << x << " "; cout << endl;
    }

    for (int i = index; i < n; i++) {
        if (sum + arr[i] <= k) {
            curr.push_back(arr[i]);
            subsetsum(arr, n, k, curr, count, i + 1);  // move to next index
            curr.pop_back();  // backtrack
        }
    }
}


void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> curr;
    int count = 0;

    subsetsum(v, n, k, curr, count, 0);

    cout << count << endl;
}

int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
