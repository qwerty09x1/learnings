#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//Maximum Sum Subarray of Size K
void maxsumsubarray(){
    int n;cin>>n;int arr[n];for(int i=0;i<n;i++){cin>>arr[i];}int k;cin>>k;
    // int start=0;int end=k;
    int currsum=0;int ans=INT_MIN;
    for(int i=0;i<k;i++){
        currsum+=arr[i];
    }
    ans=currsum;
    for(int i=k;i<n;i++){
        currsum+=arr[i]-arr[i-k];
        ans=max(ans,currsum);
    }
    cout<<ans;
}
//Longest Substring Without Repeating Characters
void longestsubstring() {
    string s; cin >> s;
    int ans = 0;
    unordered_map<char, int> mp;
    int start = 0;
    for (int end = 0; end < s.length(); end++) {
        char c = s[end];
        // If character is already in map and within current window
        if (mp.count(c) && mp[c] >= start) {
            start = mp[c] + 1; // move start to one after last occurrence
        }
        mp[c] = end; // update last seen index
        ans = max(ans, end - start + 1);
    }
    cout << ans;
}
//minimum window substring
void minwinsub(){

}
//Maximum Points from Cards
void maxpointsfromcards(){
    int n;cin>>n;int arr[n];for(int i=0;i<n;i++){cin>>arr[i];}int k;cin>>k;
}
//Minimum Size Subarray Sum
void minimumsizesubarraysum(){

}
//Sliding Window Median

//Minimum Operations to Reduce X to Zero
void minoperations(){
    int n;cin>>n;int arr[n];for(int i=0;i<n;i++){cin>>arr[i];}int k;cin>>k;

}
//Equal substrings within budget
void equalsubstrings(){
    // Change characters in s to match t within budget maxCost


}
// Minimum Swaps to Group All 1s Together
void minswapstobringsidebyside(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int countofones = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 1){
            countofones += 1;
        }
    }
    // Edge case: if no ones or all ones
    if(countofones == 0 || countofones == n){
        cout << 0 << endl;
        return;
    }
    int countofonescurr = 0;
    for(int i=0; i<countofones; i++){
        if(arr[i] == 1){
            countofonescurr += 1;
        }
    }
    int ans = countofones - countofonescurr;
    for(int i=countofones; i<n; i++){
        if(arr[i] == 1){
            countofonescurr += 1;
        }
        if(arr[i - countofones] == 1){
            countofonescurr -= 1;
        }
        ans = min(ans, countofones - countofonescurr);
    }
    cout << ans << endl;
}
// Count number of nice subarrays
void numberofsubarrays(){
    
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while (t--) {
        minswapstobringsidebyside();
    }
    return 0;
}
