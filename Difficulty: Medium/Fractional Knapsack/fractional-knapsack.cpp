// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
  
    struct Item{
        int value;
        int weight;
        Item(int v , int w){
            value = v;
            weight = w;
        }
    };
    static bool comparator(Item& a , Item& b){
        double r1 = (double)a.value/a.weight;
        double r2 = (double)b.value/b.weight;
        return r1>r2;
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
       int n = val.size();
       vector<Item>items;
       for(int i =0;i <n;i++){
           items.push_back({val[i] , wt[i]});
       }
       sort(items.begin() , items.end() , comparator);
       
       double totalVal = 0.0;
       
       for(auto &item: items){
           if(capacity == 0){
               break;
           }
           
           if(item.weight <= capacity){
               totalVal += item.value;
               capacity -= item.weight;
           }else{
               totalVal += capacity*((double)item.value/item.weight);
               break;
           }
       }
       return totalVal;
        
    }
};
