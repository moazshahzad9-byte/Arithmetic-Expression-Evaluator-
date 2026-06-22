class StackManager {
public:

    // precedence check
    int precedence(string op) {
        if(op=="+" || op=="-") return 1;
        if(op=="*" || op=="/") return 2;
        return 0;
    }

    // check if operator
    bool isOperator(string op) {
        return (op=="+" || op=="-" || op=="*" || op=="/");
    }

    // display precedence info
    void showPrecedenceTable() {
        cout << "\nOperator Precedence:\n";
        cout << "+  -  => 1\n";
        cout << "*  /  => 2\n";
    }

    // compare precedence
    bool hasHigherPrecedence(string op1, string op2) {
        return precedence(op1) >= precedence(op2);
    }

    // helper function for debugging
    void explain(string op) {
        cout << "Operator: " << op 
             << " | Precedence: " << precedence(op) << endl;
    }
};