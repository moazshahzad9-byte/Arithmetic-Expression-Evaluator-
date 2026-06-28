class ResultManager {
public:
    vector<string> history;

    void showResult(int res) {
        cout << "\nFinal Result = " << res << endl;
    }

    void addHistory(string exp) {
        history.push_back(exp);
    }

    void showHistory() {
        cout << "\n--- History ---\n";
        for(string h:history)
            cout << h << endl;
    }
};

int main() {

    ResultManager resultObj;

    while(true) {

        cout << "\n===== MENU =====\n";
        cout << "1. Calculate Expression\n";
        cout << "2. View History\n";
        cout << "3. Exit\n";

        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if(choice == 3) break;

        if(choice == 2) {
            resultObj.showHistory();
            continue;
        }

        ExpressionInput inputObj;
        Validator validatorObj;
        Tokenizer tokenObj;
        InfixToPostfix converterObj;
        Evaluator evaluatorObj;

        inputObj.showGuide();
        string expression = inputObj.getExpression();

        if(!inputObj.validateInput(expression)) continue;

        if(!validatorObj.checkCharacters(expression)) {
            cout<<"Error: Invalid Characters\n";
            continue;
        }

        if(!validatorObj.checkParentheses(expression)) {
            cout<<"Error: Unbalanced Parentheses\n";
            continue;
        }

        if(!validatorObj.checkOperators(expression)) {
            cout<<"Error: Invalid Operators\n";
            continue;
        }

        vector<string> tokens = tokenObj.tokenize(expression);
        tokenObj.display(tokens);

        string postfix = converterObj.convert(tokens);
        cout << "Postfix: " << postfix << endl;

        vector<string> pfTokens;
        string temp="";
        for(char ch:postfix) {
            if(ch==' ') {
                if(temp!="") {
                    pfTokens.push_back(temp);
                    temp="";
                }
            } else temp+=ch;
        }

        int result = evaluatorObj.evaluate(pfTokens);
        resultObj.showResult(result);

        resultObj.addHistory(expression);
    }

    return 0;
}
