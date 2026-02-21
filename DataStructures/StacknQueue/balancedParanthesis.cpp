// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> st;
//         for (int i = 0; i < s.length(); i++) {
//             if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
//                 st.push(s[i]);
//             } 
//             else {
//                 if (st.empty()) return false;
                
//                 char topChar = st.top();
//                 st.pop();
                
//                 // Match the current closing bracket s[i] with the popped opening bracket
//                 if ((s[i] == '}' && topChar != '{') ||
//                     (s[i] == ']' && topChar != '[') ||
//                     (s[i] == ')' && topChar != '(')) {
//                     return false;
//                 }
//             }
//         }
//         return st.empty();
//     }
// };