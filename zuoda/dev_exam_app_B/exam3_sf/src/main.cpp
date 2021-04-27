#include "gtest/gtest.h"
#include "exam.h"

/***
 * -------------------------------------------------------------------------------------------------------------------
 * 题目
 * -------------------------------------------------------------------------------------------------------------------
 * 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
 *  
 * 示例 1:
 * 给定二叉树 [3,9,20,null,null,15,7]
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * 返回 true 。
 * 
 * 示例 2:
 * 给定二叉树 [1,2,2,3,3,null,null,4,4]
 *        1
 *       / \
 *      2   2
 *     / \
 *    3   3
 *   / \
 *  4   4
 * 返回 false 。
 * 
 * 要求：
 * 1. 完善exam.h文件，通过所有单元测试
 * 2. 除exam.h以外的文件不得修改，修改会被覆盖
 */
class PrepareTest:public testing::Test {
protected:
    Exam _exam;
};

TEST_F(PrepareTest, test0){
    TreeNode *root = new TreeNode(100);
    root->left = new TreeNode(110);
    root->right = new TreeNode(101);

    EXPECT_EQ(_exam.isBalanced(root), true);
}

TEST_F(PrepareTest, test1){
    TreeNode *root = new TreeNode(100);
    root->left = new TreeNode(110);
    root->right = new TreeNode(101);
    root->left->left = new TreeNode(110);
    root->left->left->right = new TreeNode(110);

    EXPECT_EQ(_exam.isBalanced(root), false);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}