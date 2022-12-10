
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// top, down, left, right
// function to find the top, down, left, right for each white patch
void fun(int i,int j,vector<vector<int>> &mat,vector<vector<int>> &vis,vector<int> &zz){
    if(0<=i and i<mat.size() and 0<=j and j<mat[0].size() and mat[i][j]==1 and vis[i][j]==0){
        vis[i][j]=1;
        // to update up, left,down, right
        zz[0]=min(zz[0],i);
        zz[1]=max(zz[1],i);
        zz[2]=min(zz[2],j);
        zz[3]=max(zz[3],j);
        // checking in all 8 directions
        fun(i+1,j,mat,vis,zz);
        fun(i,j+1,mat,vis,zz);
        fun(i,j-1,mat,vis,zz);
        fun(i-1,j,mat,vis,zz);
        fun(i-1,j-1,mat,vis,zz);
        fun(i+1,j+1,mat,vis,zz);
        fun(i-1,j+1,mat,vis,zz);
        fun(i+1,j-1,mat,vis,zz);
    }
}
int main()
{
    vector<vector<double>> ans;
    // input image matrix
    vector<vector<int>> mat={{0,0,0,0,0},{0,1,1,1,0},{0,1,1,1,0},{0,0,0,0,0}};
    int r=mat.size(),c=mat[0].size();
    vector<vector<int>> vis(r,vector<int> (c,0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j]==1 and vis[i][j]==0){
                vector<int> zz={10000,0,10000,0};
                fun(i,j,mat,vis,zz);
                vector<double> res;
                // to calculate centrex , centre y, height, width
                double top=zz[0],down=zz[1],left=zz[2],right=zz[3];
                double height=down-top+1;
                double width=right-left+1;
                double cx=top+height/2;
                double cy=left+width/2;
                res.push_back(cx);
                res.push_back(cy);
                res.push_back(width);
                res.push_back(height);
                ans.push_back(res);
            }
        }
    }
    for(auto i:ans){
        cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<" "<<i[3]<<endl;
    }
    
    return 0;
}
