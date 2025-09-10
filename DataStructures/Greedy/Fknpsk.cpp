#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Pair
{
public:
    int wt;
    int pr;
    double ppk;

    Pair(int wt, int pr)
    {
        this->wt = wt;
        this->pr = pr;
        this->ppk = (double)pr / wt;
    }
    // comparator
    // for our own class (Pair), C++ has no idea how to compare objects, on what basis??
    // So we must teach it the rule → that’s the comparator.
    struct Comparator {
    bool operator()(const Pair &a, const Pair &b) const {
        return a.ppk < b.ppk;
    }
};

};

double knap(int wt[], int pr[], int n, int cap)
{
    vector<Pair> A; // array of type Pair object
    for (int i = 0; i < n; i++)
    {
        Pair p(wt[i], pr[i]); // Pair object
        A.push_back(p);       // push object to A array/vector
    }
    sort(A.begin(), A.end(),Pair::Comparator()); //sort ascending according to ppk

    int ans =0;
    for(int i=n-1;i>=0;i--){
        Pair P = A[i]; //took object 1 in P
        if(P.wt<=cap){
            //means we have capacity to have the whole weight
            ans += P.pr;
            cap-=P.wt;
        }
        else{
            ans+=cap*P.ppk;
            break;
        }

    }
    return ans;
        //now answer contains maximum protien that can be achieved 
}

int main()
{
    int wt[] = {5, 2, 1, 3, 4};
    int pr[] = {25, 10, 15, 18, 20};
    int capacity = 7;
    int n = sizeof(wt)/sizeof(wt[0]);
    double ans = knap(wt, pr, n, capacity);
    cout << "Max Profit (Fractional Knapsack): " << ans << endl;
    return 0;
}