#include<iostream>
using namespace std;
bool isSafe(vector<vector<int>>board,int row,int col,int n,int val){
    for(int i=0;i<row;i++){
        if(board[i][row]==val){
            return false;
        }
        if(board[row][i]==val){
            return false;
        }
        if(board[3*(i/3)+(i/3)][3*(i/3)+(i%3)]==val){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            if(board[i][j]==0){
                for(int val=0;val<board.size();val++){
                    if(isSafe(board,i,j,board.size(),val)){
                        board[i][j]=val;
                        if(solve(board)){
                            return true;
                        }
                        else{
                            board[i][j]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}