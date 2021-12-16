#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; //number of necklaces
    cin>>n;
    vector<string> ar(n);
    for(string &s:ar) cin>>s;
    unordered_map<char,int> mp;
    for(string s:ar)
    {
        set<char> st;
        for(char ch:s)
        {
            st.insert(ch);
        }
        for(char ch:st)
        {
            mp[ch]++;
        }
    }
    int count=0;
    for(auto ele:mp)
    {
        count = (ele.second==n)?++count:count;
    }
    cout<<count;
    return 0;
}