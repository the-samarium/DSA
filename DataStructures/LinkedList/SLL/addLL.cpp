#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *buildList(const vector<int> &v)
{
    if (v.empty())
        return nullptr;

    ListNode *head = new ListNode(v[0]);
    ListNode *curr = head;

    for (int i = 1; i < v.size(); i++)
    {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }
    return head;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int s1 = 0;
    int s2 = 0;
    ListNode *currA = l1;
    ListNode *currB = l2;
    while (currA != nullptr)
    {
        s1 += 1;
        currA = currA->next;
    }
    while (currB != nullptr)
    {
        s2 += 1;
        currB = currB->next;
    }
    cout << s1 << " " << s2 << endl;

    currA = l1;
    currB = l2;
    int res1 = 0;
    while (currA != nullptr)
    {
        res1 = res1 * 10 + currA->val;
        currA = currA->next;
    }

    int res2 = 0;
    while (currB != nullptr)
    {
        res2 = res2 * 10 + currB->val;
        currB = currB->next;
    }
    cout << res1 << " and " << res2 << endl;
    int result = res1 + res2;
    cout << result << endl;
    stack<int> st;
    while (result > 0)
    {
        st.push(result % 10); // push last digit
        result /= 10;         // remove last digit
    }
    ListNode *head = new ListNode(st.top(), nullptr);
    ListNode *curr = head;
    st.pop();
    while (!st.empty())
    {
        ListNode *temp = new ListNode(st.top(), nullptr);
        curr->next = temp;
        curr = curr->next;
        st.pop();
    }
    return head;
}

// Optional: print linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    vector<int> a = {7, 2, 4, 3};
    vector<int> b = {5, 6, 4};

    ListNode *l1 = buildList(a);
    ListNode *l2 = buildList(b);

    printList(l1); // 7 2 4 3
    printList(l2); // 5 6 4
    ListNode *hd = addTwoNumbers(l1, l2);
    printList(hd);
    return 0;
}
