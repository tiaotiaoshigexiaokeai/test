#ifndef EXAM_H
#define EXAM_H

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool IsBalanced(TreeNode *pRoot, int *pDepth)
{
    if (pRoot == nullptr) {
        *pDepth = 0;
        return true;
    }

    int left, right;

    if (IsBalanced(pRoot->left, &left) && IsBalanced(pRoot->right, &right)) {
        int diff = left - right;

        if (diff <= 1 && diff >= -1) {
            *pDepth = 1 + (left > right ? left : right);
            return true;
        }
    }

    return false;
}

class Exam
{
public:
    bool isBalanced(TreeNode *root)
    {
        int depth = 0;
        return IsBalanced(root, &depth);
    }
};

#endif // EXAM_H
