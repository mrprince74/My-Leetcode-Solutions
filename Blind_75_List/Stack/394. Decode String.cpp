//Problem Link: https://leetcode.com/problems/decode-string/

class Solution {
public:
    string decodeString(string s) {
        vector<string> st;
        for(char c : s){
            if (c == '['){
                st.push_back(string(1,c));
            }
            else if (isalpha(c) || isdigit(c)){
                if (st.empty() || st.back() == "[" || (isdigit(c) != isdigit(st.back()[0]))){
                    st.push_back("");
                }
                st.back()+= c;
            }
            else if (c == ']'){
                bool found = 0;
                string me = "";
                while(!st.empty()){
                    if (st.back() == "["){
                        if (found)
                            break;
                        else
                            found = 1;
                        st.pop_back();
                        continue;
                    }
                    // Either string or a number
                    if (isdigit(st.back()[0])){
                        int num = stoi(st.back());
                        string og = me;
                        me = "";
                        while(num--){
                            me+= og;
                        }
                    }
                    else{
                        me = st.back() + me;
                    }
                    st.pop_back();
                }
                st.push_back(me);
            }
            
        }
        return st[0];
    }
};