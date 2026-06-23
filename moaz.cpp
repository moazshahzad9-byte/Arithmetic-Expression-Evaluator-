
class Tokenizer {
public:
    vector<string> tokenize(string exp) {
        vector<string> tokens;
        string num="";

        for(char ch : exp) {
            if(isdigit(ch)) {
                num += ch;
            } else {
                if(num!="") {
                    tokens.push_back(num);
                    num="";
                }
                if(ch!=' ')
                    tokens.push_back(string(1,ch));
            }
        }

        if(num!="") tokens.push_back(num);

        return tokens;
    }
};