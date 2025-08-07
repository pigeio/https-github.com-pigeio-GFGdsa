class Solution {
  public:
    vector<string>result;
    int n;
    
    void find(vector<vector<int>>& maze ,int r , int c , string path){
        if(r<0 || r>=n || c<0 || c>=n || maze[r][c] == 0) return;
        
        if(r == n-1 && c == n-1){
            result.push_back(path);
            return;
        }
        
        maze[r][c] = 0;
        
        path.push_back('L');
        find(maze,r,c-1,path);
        path.pop_back();
                
        path.push_back('R');
        find(maze,r,c+1,path);
        path.pop_back();
                
        path.push_back('U');
        find(maze,r-1,c,path);
        path.pop_back();
                
        path.push_back('D');
        find(maze,r+1,c,path);
        path.pop_back();
                
        maze[r][c] = 1;
                
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here\
        result.clear();
        n = maze.size();
        
        if(n == 0 || maze[0][0] == 0){
            return{};
        }
        
        find(maze, 0,  0,"");
        sort(result.begin() , result.end());
        return result;
    }
};