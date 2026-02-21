#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<set>
using namespace std;

// stock span = days before it till which current stock price was highest or equal

int main() {
    vector<int> prices = {10,20,40,55,55,30};
    stack<pair<int,int>> st;
    vector<int> results;
    set<int> se;
    string ans ;
    for(int i = 0; i < prices.size(); i++) {
        string s = "sameer";
        int span = 1;   

        while(!st.empty() && st.top().first <= prices[i]) {
            span += st.top().second;
            st.pop();
        }

        st.push({prices[i], span});
        results.push_back(span);
    }

    cout << "Vector of spans of individual stocks is :" << endl;

    for(auto itr : results) {
        cout << itr << ", ";
    }

    return 0;
}
