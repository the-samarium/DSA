ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    long long s1 = 0;
    long long s2 = 0;
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
    long long res1 = 0;
    while (currA != nullptr)
    {
        res1 = res1 * 10 + currA->val;
        currA = currA->next;
    }

    long long res2 = 0;
    while (currB != nullptr)
    {
        res2 = res2 * 10 + currB->val;
        currB = currB->next;
    }
    cout << res1 << " and " << res2 << endl;
    long long result = res1 + res2;
    cout << result << endl;
    stack<long long> st;
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