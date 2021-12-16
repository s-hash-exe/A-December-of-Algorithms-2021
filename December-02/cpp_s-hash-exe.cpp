#include <bits/stdc++.h>
using namespace std;

long long int SOS(long long int n)
{
    long long int sum=0;
    while(n!=0)
    {
        sum += (n%10)*(n%10);
        n /= 10;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    set<long long int> st;
    st.insert(n);
    int prev=st.size();
    bool flag=true;
    while(n!=1)
    {
        n = SOS(n);
        st.insert(n);
        if(prev==st.size())
        {
            flag=false;
            break;
        }
        prev = st.size();
    }
    if(flag)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}