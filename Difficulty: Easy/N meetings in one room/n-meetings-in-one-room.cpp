bool comp(pair<int, int>a , pair<int , int>b){
    return a.second<b.second;
}

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        
        
        vector<pair<int , int>>couple;
        for(int i =0;i<n;i++){
            
            couple.push_back({start[i] , end[i]});
        }
        sort(couple.begin() , couple.end(), comp);
        int ending = couple[0].second;
        int meeting= 1;
        for(int i = 1; i<n ;i++){
            if(couple[i].first > ending){
                meeting++;
                ending = couple[i].second;
            }
        }
            
        
        return meeting;
    }
};