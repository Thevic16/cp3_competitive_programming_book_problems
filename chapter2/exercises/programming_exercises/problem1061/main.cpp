#include <bits/stdc++.h>

// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/
// https://www.google.com/url?sa=i&url=https%3A%2F%2Fstackoverflow.com%2Fquestions%2F64526957%2Ffind-the-digital-root-is-the-following-question-correct-i-think-it-has-some-mi&psig=AOvVaw0WZAu-uYcZIgYgEOe1J9hT&ust=1682721684792000&source=images&cd=vfe&ved=0CBMQjhxqFwoTCKCg__OQy_4CFQAAAAAdAAAAABAE

using namespace std;

class Solution {
public:
    vector<int> representative;
    //vector<int> size;

    string smallestEquivalentString(string s1, string s2, string baseStr) {

        for (int i = 0; i < 26; ++i) {
            representative.push_back(i);
            //size.push_back(1);
        }

        int n = s1.size();
        int asciiConst = 97;
        for (int i = 0; i < n; ++i) {
            combine(s1[i]- asciiConst, s2[i] - asciiConst);
        }

        string solution = "";
        int nBase = baseStr.size();
        for (int i = 0; i < nBase; ++i) {
            int ascii = find(baseStr[i]-asciiConst) + asciiConst;
            char c = char(ascii);
            solution += c;
        }

        representative.clear();
        //size.clear();

        return solution;
    }

    int find(int u)
    {
        if(u == representative[u])
            return u;

        else
            return representative[u] = find(representative[u]);
    }

    void combine (int u, int v)
    {
        u = find(u);
        v = find(v);

        if(u == v)
            return;

        else
        {
            if(u <= v)
            {
                representative[v] = u;
            }

            else
            {
                representative[u] = v;
            }

        }
    }
};

int main() {
    Solution sol = *new Solution();
    cout << sol.smallestEquivalentString("leetcode", "programs", "sourcecode");

    return 0;
}
