const int N = 1e9 + 10;
set<string> has;
void gen(){
    if (!has.empty())
        return;
    has.insert("1");
    int p = 1;
    while(p <= N / 2){
        p*= 2;
        string s = to_string(p);
        sort(s.begin(), s.end());
        has.insert(s);
    }
}
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        gen();
        string s = to_string(n);
        sort(s.begin(), s.end());
        return has.count(s);
    }
};