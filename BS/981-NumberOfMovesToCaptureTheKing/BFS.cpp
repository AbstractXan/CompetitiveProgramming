// TLE since this is too long for a large board
void updateQ(
    int r,
    int c,
    int d,
    queue<tuple<int,int,int> >& q,
    vector<vector<int>>& board){
    
    int rs =board.size();
    int cs =board[0].size();

    vector<int> possx = {-2,-2,-1,-1,1,1,2,2};
    vector<int> possy = {-1,1,-2,2,-2,2,-1,1};

    for(int i=0; i<possx.size(); i++){
        if(r+possx[i]<rs && r+possx[i]>=0){
            if(c+possy[i]<cs && c+possy[i]>=0){
                if(board[r+possx[i]][c+possy[i]]!=-1)
                    q.push(make_tuple(r+possx[i],c+possy[i],d+1));
                    //cout << r+possx[i] << " " << c+possy[i] << endl;
            }
        }
    }
    //cout << "_________________" << endl;
}
int solve(vector<vector<int>>& board) {
    unordered_map<int,unordered_map<int,int> > knight;
    int kx, ky;
    
    for(int row=0;  row<board.size() ; row++){
        for(int col=0; col<board[0].size(); col++){
            if(board[row][col]==1){
                knight[row][col]=1;
                board[row][col]==0;
                continue;
            } 
            if(board[row][col]==2){
                kx = row, ky = col;
                board[row][col]==0;
            }
        }
    }

    queue<tuple<int,int,int>> q;
    q.push(make_tuple(kx,ky,0));

    while(!q.empty()){
        tuple<int,int,int> curr = q.front();
        int row,col,depth;
        tie(row,col,depth) = curr;
        //cout << row << " " << col << endl;
        if(knight[row][col]){
            return depth;
        }
        updateQ(row,col,depth, q, board);
        board[row][col]=-1;
        q.pop();
    }
    return -1;
}