#include <bits/stdc++.h>

/*
Exercise 2.2.1*: Suppose you are given an unsorted array S of n integers. Solve each
of the following tasks below with the best possible algorithms that you can think of and
analyze their time complexities. Let’s assume the following constraints: 1 ≤ n ≤ 100K so
that O(n 2 ) solutions are theoretically infeasible in a contest environment.

1. Determine if S contains one or more pairs of duplicate integers.
2*. Given an integer v, find two integers a, b ∈ S such that a + b = v.
3*. Follow-up to Question 2: what if the given array S is already sorted ?
 I don't see right now how to sort help to improve the solution in this problem.

4*. Print the integers in S that fall between a range [a . . . b] (inclusive) in sorted order.
    Easy one, just a while or for with that condition.

5*. Determine the length of the longest increasing contiguous sub-array in S.
    I think is easy too, just doing a for and a cont that restart when sub-array is no increasing.

6. Determine the median (50th percentile) of S. Assume that n is odd.
*/

using namespace std;

bool questionOne(int S[], int n) {
    unordered_set<int> op;

    for (int i = 0; i < n; ++i) {
        op.insert(S[i]);
    }

    return op.size() != n;
}


// b = v - S[i]
// a = S[i]
pair<int, int> questionTwo(int S[], int n, int v) {
    map<int, int> bToA;

    for (int i = 0; i < n; ++i) {
        int a = S[i];
        int b = v - S[i];

        if(bToA.find(b) != bToA.end()) {
            return pair(a, b);
        }
        else {
            bToA[a] = 1;
        }
    }

    return pair(-1, -1);
}

int main() {
    int n = 10;
    int S[] = {1, 23, 47, 26, 5, 62, 74, 7, 3, 34};
    int S2[] = {34, 23, 47, 26, 3, 62, 74, 7, 3, 34};

    cout << "Question one:" << endl;
    cout << questionOne(S, n) << endl;
    cout << questionOne(S2, n) << endl;

    cout << "Question two:" << endl;
    pair<int, int> resultQuestionTwo1 = questionTwo(S, n, 24);
    cout << resultQuestionTwo1.first << " + " << resultQuestionTwo1.second << " = " << resultQuestionTwo1.first +
    resultQuestionTwo1.second << endl;
    pair<int, int> resultQuestionTwo2 = questionTwo(S, n, 37);
    cout << resultQuestionTwo2.first << " + " << resultQuestionTwo2.second << " = " << resultQuestionTwo2.first +
    resultQuestionTwo2.second << endl;
    pair<int, int> resultQuestionTwo3 = questionTwo(S2, n, 6);
    cout << resultQuestionTwo3.first << " + " << resultQuestionTwo3.second << " = " << resultQuestionTwo3.first +
    resultQuestionTwo3.second << endl;
    pair<int, int> resultQuestionTwo4 = questionTwo(S2, n, 100);
    cout << resultQuestionTwo4.first << " + " << resultQuestionTwo4.second << " = " << resultQuestionTwo4.first +
    resultQuestionTwo4.second << endl;
    pair<int, int> resultQuestionTwo5 = questionTwo(S2, n, 101);
    cout << resultQuestionTwo5.first << " + " << resultQuestionTwo5.second << " = " << resultQuestionTwo5.first +
            resultQuestionTwo5.second << endl;

    return 0;
}


