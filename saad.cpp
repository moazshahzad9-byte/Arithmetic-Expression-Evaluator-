class Validator {
public:
    bool checkCharacters(string exp) {
        for(char ch : exp) {
            if(!(isdigit(ch) || ch=='+' || ch=='-' ||
                 ch=='*' || ch=='/' || ch=='(' ||
                 ch==')' || ch==' '))
                return false;
        }
        return true;
    }

    bool checkParentheses(string exp) {
        stack<char> st;
        for(char ch : exp) {
            if(ch=='(') st.push(ch);
            else if(ch==')') {
                if(st.empty()) return false;
                st.pop();
            }
        }
        return st.empty();
    }

    bool hasBrackets(string exp) {
        for(char ch : exp) {
            if(ch=='(' || ch==')') return true;
        }
        return false;
    }
};
