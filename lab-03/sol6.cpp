#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<string> st;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (isalpha(s[i])) {  
            st.push(string(1, s[i])); 
        } 
        else {  // Operator case
            if (st.size() < 2) {
                cout << "Invalid postfix expression\n";
                return 1;
            }
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();
            st.push("(" + b + s[i] + a + ")"); 
        }
    }

    // Final result
    if (st.size() == 1) {
        cout << "Infix expression: " << st.top() << endl;
    } else {
        cout << "Invalid postfix expression\n";
    }

    return 0;
}
