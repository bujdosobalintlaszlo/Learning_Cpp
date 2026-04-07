class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int (int,int)>> map = {
            {"+",[](int x, int y) {return x+y;}},
            {"-",[](int x, int y) {return x-y;}},
            {"*",[](int x, int y) {return x*y;}},
            {"/",[](int x, int y) {return x/y;}},

        };
        std::stack<int> st;
        for(std::string& s : tokens){
            if(!map.count(s)){
                st.push(stoi(s));
            }else{
                int operand1 = st.top();
                st.pop();
                int operand2 = st.top();
                st.pop();
                st.push(map[s](operand2,operand1));
            }
        }
        return st.top();
    }
};
