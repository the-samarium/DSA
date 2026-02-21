#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int Stockspan(int idx, vector<int>& prices) {
    int span = 0;
    int currPrice = prices[idx];

    for (int i = idx ; i >= 0; i--) {
        if (prices[i] <= currPrice)
            span++;
        else
            break;
    }
    return span;
}

int StockSpanStk(int idx, vector<int>& prices){
    stack<int> st;
    //push elements till idx on stack
    int span = 0;
    for(int i=0;i<=idx;i++){
        st.push(prices[i]);
    }

    while(st.top()<=prices[idx]){
        span++;
        st.pop();
    }
    return span;
}



int main(){
    vector<int> prices ={7,34,1,2};
    // cout<<Stockspan(1,prices)<<endl;
    cout<<StockSpanStk(1,prices);
    //find span of 
    return 0;
}