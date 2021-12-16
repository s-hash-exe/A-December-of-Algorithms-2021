#include <bits/stdc++.h>
using namespace std;

bool findWord(vector<vector<char>> &ar, vector<vector<int>> &vis, int n, int m, int x, int y, string word, int k)
{
    if((x<0)||(x>=n)||(y<0)||(y>=m))
    {
        return false;
    }
    if(k==word.size())
    {
        return true;
    }
    if(ar[x][y]==word[k] && vis[x][y]==0)
    {
        vis[x][y]=1;
        bool rv = (findWord(ar,vis,n,m,x+1,y,word,k+1)||
                  findWord(ar,vis,n,m,x,y+1,word,k+1)||
                  findWord(ar,vis,n,m,x-1,y,word,k+1)||
                  findWord(ar,vis,n,m,x,y-1,word,k+1));
        vis[x][y]=0;
        return rv;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    bool flag=false;
    string name;
    cin>>n>>m;
    vector<vector<char>> ar(n,vector<char>(m));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>ar[i][j];
        }
    }
    cin>>name;
    for(int i=0; (i<n && !flag); i++)
    {
        for(int j=0; j<m; j++)
        {
            if(ar[i][j]==name[0])
            {
                vector<vector<int>> vis(n,vector<int>(m,0));
                if(findWord(ar,vis,n,m,i,j,name,0))
                {
                    flag=true;
                    break;
                }
            }
        }
    }
    if(flag)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false";
    }
    return 0;
}