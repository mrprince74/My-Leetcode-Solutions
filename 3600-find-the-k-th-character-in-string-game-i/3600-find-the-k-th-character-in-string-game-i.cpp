class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        auto addOne = [&](string& s){
            for(char& c : s){
                if (c == 'z')
                    c = 'a';
                else
                    c++;
            }
        };
        while(word.size() < k){
            string newWord = word;
            addOne(word);
            newWord+= word;
            word = newWord;
        }
        return word[k-1];
    }
};