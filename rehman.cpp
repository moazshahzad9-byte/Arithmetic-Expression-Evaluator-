// ================= MEMBER 5 =================
class InfixToPostfix {
public:
    string convert(vector<string> tokens) {

        stack<string> st;
        string postfix="";
        StackManager sm;

        for(string token : tokens) {

            if(isdigit(token[0])) {
                postfix += token + " ";
            }
            else if(token=="(") {
                st.push(token);
            }
            else if(token==")") {
                while(!st.empty() && st.top()!="(") {
                    postfix += st.top() + " ";
                    st.pop();
                }
                if(!st.empty()) st.pop();
            }
            else {
                while(!st.empty() &&
                      sm.precedence(st.top()) >= sm.precedence(token)) {
                    postfix += st.top() + " ";
                    st.pop();
                }
                st.push(token);
            }
        }

        while(!st.empty()) {
            postfix += st.top() + " ";
            st.pop();
        }

        return postfix;
    }
};
