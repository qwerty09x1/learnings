#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//2 Sum II > Input array is sorted> Given a one indexed array of integers numbers, that is already sorted in non-decreasing order, find two numbers such that
// they add up to a specific target number. Return the indices of the two numbers.
void solvetwosum() {
    int n, target;
    cin >> n >> target;
    int arr[n + 1]; // 1-indexed
    unordered_map<int, int> mp;
    // First pass: store all values and their indices
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        mp[arr[i]] = i;
    }
    // Second pass: search for complement
    for (int i = 1; i <= n; i++) {
        int complement = target - arr[i];
        // Ensure we don't use the same index twice
        if (mp.count(complement) && mp[complement] != i) {
            cout << i << " " << mp[complement] << "\n";
            return;
        }
    }
    cout << "No valid pair found.\n";
}
// Container with most water > Given n non negative integers as the height of vertical lines, find two lines that together with the x-axis form a container that can hold the most water.
void containerwithmostwater() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int l = 0, r = n - 1;
    int max_area = 0;
    while (l < r) {
        int height = min(arr[l], arr[r]);
        int width = r - l;
        max_area = max(max_area, height * width);
        // Move the pointer pointing to the shorter line
        if (arr[l] < arr[r]) {
            l++;
        } else {
            r--;
        }
    }
    cout << max_area << "\n";
}
// 3Sum > Given an integer nums, return all unique triplets(nums[i],nums[j],nums[k]) such that i!=j!=k and nums[i]+nums[j]+nums[k]=0
void threesum() {
    int n;cin >> n;vector<int> arr(n);for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    bool found = false;
    vector<vector<int>> ans;
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue; // skip duplicate first elements
        int l = i + 1, r = n - 1;
        while (l < r) {
            int sum = arr[i] + arr[l] + arr[r];
            if (sum == 0) {
                ans.push_back({arr[i], arr[l], arr[r]});
                found = true;
                // Skip duplicates on the left
                while (l < r && arr[l] == arr[l + 1]) l++;
                // Skip duplicates on the right
                while (l < r && arr[r] == arr[r - 1]) r--;
                l++;
                r--;
            } else if (sum < 0) {
                l++;
            } else {
                r--;
            }
        }
    }
    if (found) {
        for (auto &triplet : ans) {
            cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << "\n";
        }
    } else {
        cout << "Not present\n";
    }
}
// Move Zeroes > Given an array, move all zeroes to the end in-place.
void movezeroes(){
    int n;cin >> n;int arr[n]; for (int i = 0; i < n; i++) {cin >> arr[i];}

}
//Sort colors, Dutch National Flag > Given an array with n objects colored red, white or blue (represented by integers 0,1 , and 2), sort
// so that objects of the same color are adjacent, with colors in order red, white, and blue.
void sortcolors(){
    int n;cin >> n;int arr[n]; for (int i = 0; i < n; i++) {cin >> arr[i];}

}
//Minimum size subarray sum > Given an array of +ve integers and a target, return the length of a contiguous array whose sum is greater than or 
// equal to target. If no such subarray exits, return 0. 
void minimumsizesubarraysum(){
    int n,target;cin>>n>>target;int arr[n]; for (int i = 0; i < n; i++) {cin >> arr[i];}
    int l = 0, sum = 0, ans = INT_MAX;
        for (int r = 0; r < n; r++) {
            sum += arr[r];
            while (sum >= target) {
                ans = min(ans, r - l + 1);
                sum -= arr[l];
                l++;
            }
        }
        cout<<((ans == INT_MAX) ? 0 : ans);
    }
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while (t--) {
        minimumsizesubarraysum();
    }
    return 0;
}
