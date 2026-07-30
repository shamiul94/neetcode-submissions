
/*
n = 2

States: 

fun(2, "", 0, 0)
  - fun(2, "(", 1, 0)
    - fun(2, "((", 2, 0)
        - fun(2, "(((", 3, 0)
            - return 
        - fun(2, "(()", 2, 1)
            - fun(2, "(()(", 3, 1)
                - return
            - fun(2, "(())", 2, 2)
                - valid
    - fun(2, "()", 1, 1)
        - fun(2, "()(", 2, 1)
            - fun(2, "()((", 3, 1)
                - return
            - fun(2, "()()", 2, 2)
                - valid
        - fun(2, "())", 1, 2)
            - return
  - fun(2, ")", 0, 1)
    - return

*/

class Solution {
public:
    void backtrack(int n, string curr, int openPar, int closePar, vector<string>& res) {
        if(closePar > openPar) {
            return;
        }

        if(openPar > n || closePar > n) {
            // not valid case
            return;
        }

        if(openPar == n && closePar == n) {
            // valid case
            res.push_back(curr); 
            return;
        }

        curr.push_back('(');
        backtrack(n, curr, openPar+1, closePar, res);
        curr.pop_back(); 

        curr.push_back(')'); 
        backtrack(n, curr, openPar, closePar+1, res);
        curr.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(n, "", 0, 0, res);
        return res;
    }
};
