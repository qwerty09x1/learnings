#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//Evaluate Reverse Polish Notation(Medium)
int reversepolishnotation(vector<string>&tokens){

}
//Monotonic Stack Next Greater Element -1 > Find the next greater number for each element in nums1 from nums2
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
    unordered_map<int,int> mp;
    stack<int> st;
    for(int i=0;i<nums2.size();i++){
        st.push(nums2[i]);
    }
    // while()
}
//Next Greater Element -2 > Given a circular integer array, find the next greater number for every element
vector<int> nextGreaterElement2(vector<int>&nums){

}
//Simplify Path
// string simplifyPath(string path){
//     stack<char>s;
//     string ans;
//     for(int i=s.size()-1;i>=0;i--){
//         s.push(path[i]);
//     }
//     while(!s.empty()){
//         char c =s.top();
//         s.pop();
//         char next=s.top();
//         if(c=='/' && next=='/'){
//             ans.push_back(c);
//             s.pop();
//         }
//         ans.push_back(c);
//     }
//     return ans;

// }
//Trapping Rain Water
void trappingrain(){
    int n;cin>>n;vector<int> height;
    for(int i=0;i<n;i++){
       cin>> height[i];
    }
    //logic
     
}

void solveNGE(){
    int n,m;
    cin>>n>>m;
    vector<int> nums1;
    for(int i=0;i<n;i++){int x;cin>>x;nums1.push_back(x);}
    vector<int> nums2;
    for(int i=0;i<n;i++){int x;cin>>x;nums2.push_back(x);}
}

// void solvesimplifypath(){
//     string s;
//     cin>>s;
//     cout<<simplifyPath(s);


/*
Next Greater element to the right-Given an array of integers, find the next greater element for each element. The next greater element for an element x is the first greater element on the right side of x in the array.
*/
void ngr(){
    int n;cin>>n;int arr[n];for(int i=0;i<n;i++){cin>>arr[i];}
    vector<int> ngr;
    stack<int> s;
    for(int i = n - 1; i >= 0; i--) {
        // Remove elements smaller than or equal to current
        while(!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        // If stack is empty, no greater element to the right
        if(s.empty()) {
            ngr.push_back(-1);
        } else {
            ngr.push_back(s.top());
        }
        // Push current element for future comparisons
        s.push(arr[i]);
    }
    // Reverse to match original order
    reverse(ngr.begin(), ngr.end());
    for(int x : ngr) {
        cout << x << " ";
    }
    cout << endl;
}
/*
Next Greater element to the left -Given an array, find the previous greater element for each element. The previous greater element for an element x is the first greater element on the left side of x.
*/
void ngl(){
    int n;cin>>n;int arr[n];for(int i=0;i<n;i++){cin>>arr[i];}
    vector<int> ngr;
    stack<int> s;
    for(int i = n - 1; i >= 0; i--) {
        // Remove elements smaller than or equal to current
        while(!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        // If stack is empty, no greater element to the right
        if(s.empty()) {
            ngr.push_back(-1);
        } else {
            ngr.push_back(s.top());
        }
        // Push current element for future comparisons
        s.push(arr[i]);
    }
    // Reverse to match original order
    reverse(ngr.begin(), ngr.end());
    for(int x : ngr) {
        cout << x << " ";
    }
    cout << endl;
}
/*
Next Smaller element to the left- Find the previous smaller element for each element in the array.
*/
void nsl(){
}
/*
Next Smaller element to the right- Find the next smaller element for each element in the array.
*/
void nsr(){
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while (t--) {
        ngr();
    }
    return 0;
}



