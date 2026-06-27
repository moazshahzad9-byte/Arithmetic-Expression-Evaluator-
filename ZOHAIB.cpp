class ExpressionInput {
public:
    string getExpression() {
        string exp;
        cout << "\nEnter Expression: ";
        getline(cin, exp);
        return exp;
    }

    bool validateInput(string exp) {
        if(exp.empty()) {
            cout << "Error: Empty Input\n";
            return false;
        }
        return true;
    }

    void showGuide() {
        cout << "\nAllowed: + - * / ( )\n";
        cout << "Example: (2+3)*4\n";
    }
}
