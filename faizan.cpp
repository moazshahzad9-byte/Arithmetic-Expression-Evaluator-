class Evaluator {
public:
    int operate(int a,int b,string op) {
        if(op=="+") return a+b;
        if(op=="-") return a-b;
        if(op=="*") return a*b;
        if(op=="/") {
            if(b==0) {
                cout<<"Error: Division by zero\n";
                exit(0);
            }
            return a/b;
        }
        return 0;
    }

    int evaluate(vector<string> tokens) {

        stack<int> st;

        cout << "\nSteps:\n";

        for(string token : tokens) {

            if(isdigit(token[0])) {
                st.push(stoi(token));
            }
            else {
                int b=st.top(); st.pop();
                int a=st.top(); st.pop();

                int res = operate(a,b,token);

                cout << a << " " << token << " " << b << " = " << res << endl;

                st.push(res);
            }
        }

        return st.top();
    }
};