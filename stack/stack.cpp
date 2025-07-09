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
string simplifyPath(string path){
    stack<char>s;
    string ans;
    for(int i=s.size()-1;i>=0;i--){
        s.push(path[i]);
    }
    while(!s.empty()){
        char c =s.top();
        s.pop();
        char next=s.top();
        if(c=='/' && next=='/'){
            ans.push_back(c);
            s.pop();
        }
        ans.push_back(c);
    }
    return ans;

}
void solveNGE(){
    int n,m;
    cin>>n>>m;
    vector<int> nums1;
    for(int i=0;i<n;i++){int x;cin>>x;nums1.push_back(x);}
    vector<int> nums2;
    for(int i=0;i<n;i++){int x;cin>>x;nums2.push_back(x);}
}

void solvesimplifypath(){
    string s;
    cin>>s;
    cout<<simplifyPath(s);
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while (t--) {
        solveNGE();
    }
    return 0;
}



