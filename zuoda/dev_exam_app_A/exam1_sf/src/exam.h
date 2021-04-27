#ifndef EXAM_H
#define EXAM_H

#include <vector>
#include <string>

using namespace std;

void Permutation(string p, const int k, const int m, vector<string> &res)
{
    if (k == m) {
        res.push_back(p);
    }

    for (int i = k; i <= m; i++) { //用一个for循环代替下面的
        swap(p[k], p[i]); //交换两个数
        Permutation(p, k + 1, m, res);
    }
}

string sortString(string p)
{
    int a = p.length();
    for (int i = 0; i <= a - 1; i++) {
        for (int j = 0; j < a - 1 - i; j++) {
            if (p[j + 1] < p[j])
                swap(p[j + 1], p[j]);
        }
    }
    return p;
}

class Exam
{
public:
    vector<string> output(string input)
    {
        int length = input.length();
        input = sortString(input);
        vector<string> res;
        Permutation(input, 0, length - 1, res);
        return res;
    }
};

#endif // EXAM_H
